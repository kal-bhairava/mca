# Run this ONCE (needs internet) to save the PM2.5 data as a CSV file.
# After that the app works without internet.
#   uv run python download_pm25.py

import requests
import pandas as pd

from src.data import FOLDER, districts

parts = []
for name, (lat, lon) in districts.items():
    print("Downloading", name)
    params = {"latitude": lat, "longitude": lon, "hourly": "pm2_5",
              "start_date": "2022-08-01", "end_date": "2026-09-30"}
    data = requests.get("https://air-quality-api.open-meteo.com/v1/air-quality", params=params).json()["hourly"]

    hourly = pd.DataFrame({"time": pd.to_datetime(data["time"]), "pm25": data["pm2_5"]})
    hourly["month"] = hourly["time"].dt.to_period("M").dt.to_timestamp()

    monthly = hourly.groupby("month")["pm25"].mean().round(2).reset_index()
    monthly["district"] = name
    parts.append(monthly)

pm = pd.concat(parts)[["district", "month", "pm25"]]
pm.to_csv(FOLDER + "punjab_pm25_monthly.csv", index=False)
print("Saved", len(pm), "rows")
