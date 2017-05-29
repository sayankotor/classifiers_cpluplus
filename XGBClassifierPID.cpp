
#include "XGBClassifierPID.h"
#include<iostream>

XGBClassifierPID::XGBClassifierPID()
{
  XGDMatrixCreateFromMat(
      &m_predictionsCache.at(0),
      1,
      2,
      0.5,
      &m_cache_matrix);
}

void XGBClassifierPID::setPath(const std::string& path)
{
  XGBoosterCreate(&m_cache_matrix, 1, &m_booster);
  XGBoosterLoadModel(m_booster, path.c_str());
}

std::vector<double> XGBClassifierPID::getClassifierValues(const std::vector<double>& featureValues)
{
  // currently XGBoost only supports float
  std::vector<float> features_f(featureValues.begin(), featureValues.end());

  // fill the feature vector into a XGBoost DMatrix
  XGDMatrixCreateFromMat(&features_f.at(0),
                         1,
                         features_f.size(),
                         0,
                         &m_feature_matrix);

  // XGBoost returns the predictions into a arrayish object and return
  // its size
  unsigned long predictions_length;
  const float *predictions;
  XGBoosterPredict(m_booster,
                   m_feature_matrix,
                   0,
                   0,
                   &predictions_length,
                   &predictions);

    std::vector<double> vec_predictions;
    for (int i =0; i<predictions_length; i++){
        vec_predictions.push_back(predictions[i]);
    }
    return vec_predictions;
}
