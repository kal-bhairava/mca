import pandas as pd

# dataset folder of this repo (path is from the ui folder)
FOLDER = "../../../../dataset/projects/sem-1/dsf/"

# centre point of each district (used for the map and to download PM2.5)
districts = {
    "Amritsar": (31.63, 74.87), "Bathinda": (30.21, 74.95), "Faridkot": (30.67, 74.76),
    "Fatehgarh Sahib": (30.65, 76.39), "Firozpur": (30.93, 74.61), "Gurdaspur": (32.04, 75.40),
    "Hoshiarpur": (31.53, 75.91), "Jalandhar": (31.33, 75.58), "Kapurthala": (31.38, 75.38),
    "Ludhiana": (30.90, 75.85), "Mansa": (29.99, 75.40), "Moga": (30.82, 75.17),
    "Muktsar": (30.47, 74.52), "Nawan Shehar": (31.12, 76.12), "Patiala": (30.34, 76.39),
    "Rupnagar": (30.97, 76.53), "Sangrur": (30.25, 75.84),
}


def load_satellite():
    sat = pd.read_csv(FOLDER + "punjab_monthly_ndvi_lst.csv")
    sat = sat.rename(columns={"ADM2_NAME": "district"})
    sat["month"] = pd.to_datetime(sat["month"])

    keep = {"ndvi_all": "ndvi", "lst_all": "ground_temp",
            "lst_trees": "ground_temp_trees", "lst_crops": "ground_temp_crops"}
    for old, new in keep.items():
        usual = sat.groupby("district")[f"{old}_count"].transform("max")
        sat[new] = sat[f"{old}_mean"].where(sat[f"{old}_count"] >= usual / 2)
    return sat[["district", "month", *keep.values()]]


def load_weather():
    weather = pd.read_csv(FOLDER + "punjab_weather_daily.csv", parse_dates=["time"])
    weather["month"] = weather["time"].dt.to_period("M").dt.to_timestamp()
    return (
        weather.groupby(["district", "month"])
        .agg(air_temp=("temperature_2m_mean", "mean"), rain=("precipitation_sum", "sum"))
        .reset_index()
    )


def load_pm25():
    return pd.read_csv(FOLDER + "punjab_pm25_monthly.csv", parse_dates=["month"])


def load_data():
    df = load_satellite().merge(load_weather(), on=["district", "month"], how="left")
    df = df.merge(load_pm25(), on=["district", "month"], how="left")

    # anomaly = this month minus the usual value for that district and month
    cols = ["ndvi", "ground_temp", "air_temp", "rain", "pm25"]
    normal = df.groupby(["district", df["month"].dt.month])[cols].transform("mean")
    for c in cols:
        df[c + "_anom"] = df[c] - normal[c]
    return df
