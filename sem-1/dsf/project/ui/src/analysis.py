import statsmodels.api as sm


def regression(data, outcome):
    """outcome' = a + b1*NDVI' + b2*Rain'
    returns: effect of +0.1 NDVI, p-value, R²"""
    rows = data.dropna(subset=["ndvi_anom", "rain_anom", outcome])
    X = sm.add_constant(rows[["ndvi_anom", "rain_anom"]])
    model = sm.OLS(rows[outcome], X).fit()

    effect = round(model.params["ndvi_anom"] * 0.1, 2)
    p = round(model.pvalues["ndvi_anom"], 3)
    r2 = round(model.rsquared, 2)
    return effect, p, r2
