#ifndef XGBCLASSIFIER_H
#define XGBCLASSIFIER_H

#include <string>
#include <vector>
#include "xgboost/include/xgboost/c_api.h"

class IClassifier
{
public:

    /**    * @brief      Main classification method    *
           * Takes a vector of values of features and returns the corresponding MVA
           * output.
           *    * @param[in]  featureValues  A vector of feature values
           *    * @return     MVA classifier value    */
    virtual std::vector<double> getClassifierValues(const std::vector<double>& featureValues) = 0;
};

class XGBClassifierPID : public IClassifier {
  public:
    XGBClassifierPID();
    std::vector<double> getClassifierValues(const std::vector<double>& featureValues) override;
    void setPath(const std::string& path);

  private:
    std::vector<float> m_predictionsCache = {0, 0};
    DMatrixHandle m_cache_matrix,
                  m_feature_matrix;
    BoosterHandle m_booster;
};


#endif // XGBCLASSIFIER_H
