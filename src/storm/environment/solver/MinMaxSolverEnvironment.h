#pragma once

#include "storm/environment/solver/SolverEnvironment.h"

#include "storm/adapters/RationalNumberAdapter.h"
#include "storm/solver/MultiplicationStyle.h"
#include "storm/solver/SolverSelectionOptions.h"

namespace storm {

class MinMaxLpSolverEnvironment;

class MinMaxSolverEnvironment {
   public:
    MinMaxSolverEnvironment();
    ~MinMaxSolverEnvironment();

    storm::solver::MinMaxMethod const& getMethod() const;
    bool const& isMethodSetFromDefault() const;
    void setMethod(storm::solver::MinMaxMethod value, bool isSetFromDefault = false);
    uint64_t const& getMaximalNumberOfIterations() const;
    void setMaximalNumberOfIterations(uint64_t value);
    storm::RationalNumber const& getPrecision() const;
    void setPrecision(storm::RationalNumber value);
    bool const& getRelativeTerminationCriterion() const;
    void setRelativeTerminationCriterion(bool value);
    storm::RationalNumber const& getABOVIEffectiveTolerance() const;
    void setABOVIEffectiveTolerance(storm::RationalNumber const& value);
    storm::RationalNumber const& getABOVISpectralUpperBound() const;
    void setABOVISpectralUpperBound(storm::RationalNumber const& value);
    storm::RationalNumber const& getABOVISpectralLowerBound() const;
    void setABOVISpectralLowerBound(storm::RationalNumber const& value);
    storm::solver::MultiplicationStyle const& getMultiplicationStyle() const;
    void setMultiplicationStyle(storm::solver::MultiplicationStyle value);
    bool isForceRequireUnique() const;
    void setForceRequireUnique(bool value);
    MinMaxLpSolverEnvironment const& lp() const;
    MinMaxLpSolverEnvironment& lp();

   private:
    storm::solver::MinMaxMethod minMaxMethod;
    bool methodSetFromDefault;
    uint64_t maxIterationCount;
    storm::RationalNumber precision;
    bool considerRelativeTerminationCriterion;
    storm::RationalNumber aboviEffectiveTolerance;
    storm::RationalNumber aboviSpectralUpperBound;
    storm::RationalNumber aboviSpectralLowerBound;
    storm::solver::MultiplicationStyle multiplicationStyle;
    bool forceRequireUnique;
    SubEnvironment<MinMaxLpSolverEnvironment> lpEnvironment;
};
}  // namespace storm
