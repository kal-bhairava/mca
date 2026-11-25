# DSF Project UI (Streamlit)

The app reads the CSV files from `dataset/projects/sem-1/dsf/` in this repo, so it works without internet.

Run from this folder:

```
uv run streamlit run app.py
```

`punjab_pm25_monthly.csv` is already saved. To download fresh PM2.5 data (needs internet), run:

```
uv run python download_pm25.py
```
