import streamlit as st

from src.data import load_data
from src import pages

st.set_page_config(page_title="DSF Project", page_icon=":material/forest:")
df = load_data()

# sidebar
st.sidebar.title("DSF Project")
st.sidebar.write("Sakshi Devi (2026010101)")
st.sidebar.write("Roshan Singh (2026010096)")
page = st.sidebar.radio("Go to", ["Home", "Data", "Seasons", "Trees vs Crops", "Temperature", "Health", "Conclusion"])
district = st.sidebar.selectbox("District", ["All"] + sorted(df["district"].unique()))

if district == "All":
    data = df
else:
    data = df[df["district"] == district]

# show the selected page
if page == "Home":
    pages.home()
elif page == "Data":
    pages.data_page(data)
elif page == "Seasons":
    pages.seasons(data)
elif page == "Trees vs Crops":
    pages.trees_vs_crops(df)
elif page == "Temperature":
    pages.temperature(data)
elif page == "Health":
    pages.health(data, df)
elif page == "Conclusion":
    pages.conclusion()
