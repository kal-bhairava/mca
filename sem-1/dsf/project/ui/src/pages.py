import pandas as pd
import streamlit as st

from src.data import districts
from src.analysis import regression


def home():
    st.title("Urban Green Cover vs Climate and Health Risk")
    st.write("Subject: MCA109 Data Science Foundation")

    st.header("Problem")
    st.write("Cities in Punjab are growing and green cover is going down. This can make areas hotter "
             "and the air more polluted (PM2.5). In this project we check how much green cover (NDVI) "
             "affects temperature and air quality using real satellite and weather data.")

    st.header("Questions")
    st.write("1. How do greenness, temperature and rain change during the year?")
    st.write("2. Are areas with trees cooler than crop areas?")
    st.write("3. Are greener months cooler?")
    st.write("4. Are greener months less polluted (PM2.5)?")

    st.header("Datasets")
    st.write("- Google Earth Engine MODIS: NDVI and ground temperature")
    st.write("- Open-Meteo Historical Weather (ERA5): air temperature and rain")
    st.write("- Open-Meteo Air Quality (CAMS): PM2.5")

    st.header("Study area: 17 districts of Punjab")
    points = pd.DataFrame(districts.values(), columns=["lat", "lon"])
    st.map(points)


def data_page(data):
    st.title("Data")
    st.write("Rows:", len(data))
    st.dataframe(data[["district", "month", "ndvi", "ground_temp", "air_temp", "rain", "pm25"]])

    st.subheader("Statistics")
    st.dataframe(data[["ndvi", "ground_temp", "air_temp", "rain", "pm25"]].describe().round(2))


def seasons(data):
    st.title("Average for each month of the year")
    avg_year = data.groupby(data["month"].dt.month)[["ndvi", "ground_temp", "air_temp", "rain"]].mean()
    for col in avg_year.columns:
        st.subheader(col)
        st.line_chart(avg_year[col])

    st.write("**Result:** NDVI peaks with wheat (Feb-Mar) and rice (Aug). Heat peaks in May-June. "
             "Rain is heavier in June-Sept.")


def trees_vs_crops(df):
    st.title("Are areas with trees cooler?")
    st.write("Ground temperature of tree pixels minus crop pixels. Negative = trees are cooler.")

    gap = (df["ground_temp_trees"] - df["ground_temp_crops"]).groupby(df["district"]).mean()
    gap = gap.dropna().sort_values()
    st.bar_chart(gap)

    st.write(f"**Result:** Tree areas are on average {abs(gap.mean()):.1f} °C cooler than crop areas.")


def temperature(data):
    st.title("Are greener months cooler?")
    st.scatter_chart(data, x="ndvi_anom", y="ground_temp_anom")

    st.write("Linear regression: T' = a + b1·NDVI' + b2·Rain'")
    for outcome in ["ground_temp_anom", "air_temp_anom"]:
        effect, p, r2 = regression(data, outcome)
        st.write(f"{outcome}: +0.1 NDVI -> {effect} °C  (p = {p}, R² = {r2})")


def health(data, df):
    st.title("Health risk: PM2.5")
    st.write("PM2.5 data is available from Aug 2022. India safe limit is 60 µg/m³.")
    pm = data.dropna(subset=["pm25"])
    st.write("Average PM2.5:", round(pm["pm25"].mean(), 1), "µg/m³")

    st.subheader("Average PM2.5 by month of year")
    st.bar_chart(pm.groupby(pm["month"].dt.month)["pm25"].mean())

    st.subheader("Average PM2.5 by district")
    st.bar_chart(df.groupby("district")["pm25"].mean().sort_values())

    st.subheader("Health risk category (India AQI)")
    bands = [0, 30, 60, 90, 120, 250, 1000]
    labels = ["Good", "Satisfactory", "Moderate", "Poor", "Very Poor", "Severe"]
    risk = pd.cut(pm["pm25"], bins=bands, labels=labels)
    st.bar_chart(risk.value_counts().reindex(labels))

    effect, p, r2 = regression(data, "pm25_anom")
    st.write(f"pm25_anom: +0.1 NDVI -> {effect} µg/m³  (p = {p}, R² = {r2})")
    st.write("**Result:** Air is worst in Nov-Jan (stubble burning and cold weather). "
             "Greener months have slightly cleaner air.")


def conclusion():
    st.title("Conclusion")
    st.markdown("""
| Outcome | +0.1 NDVI | p-value | R² |
|---|---|---|---|
| Ground temperature | −1.00 °C | < 0.001 | 0.14 |
| Air temperature | −0.39 °C | < 0.001 | 0.22 |
| PM2.5 | −5.29 µg/m³ | < 0.001 | 0.03 |
""")
    st.write("- Greener months were cooler: about 1 °C on the ground and 0.4 °C in the air.")
    st.write("- Greener months also had a little less PM2.5.")
    st.write("- All results are significant, but R² is low, so greenness explains only a small part.")
    st.write("- This shows a link, not a cause. Most green areas in Punjab are crop fields, not forests.")
