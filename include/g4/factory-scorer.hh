#include <vector>
#include <string>
#include <memory>


//abstract base class :
class BaseCounter {
public:
  virtual void Increment(float &value_) = 0;
  virtual float GetValue() const = 0;
  virtual std::string GetName() = 0;
  
};

//different realization of scorer:

//scoring by simple increment
class IntCounter : public BaseCounter {
public:
  void Increment(float &value_) override {
    ++value_;
  }

  float GetValue() const override {
    return value_;
  }

  std::string GetName() override {
    return "simple counter";
  }

private:
  float value_ = 0;
};

//scoring by Nikita's algorithm

class NikitaCounter : public BaseCounter {
public:
  void Increment(float &value_) override {
    //value_ += 0.1;
    elements_.push_back(value_);

  }
  float GetValue() const override {
        float value_ = 0.;
        for (int i = 0; i < elements_.size(); i+=2) {
            value_ += elements_[i];
            value_ += elements_[i+1];
  }
    return static_cast<float>(value_);
  }
  std::string GetName() override {
    return "Nikita's algorithm";
  }

private:
  vector<float> elements_;
  float value_ = 0.0;
};

//scoring by Polina's algorithm

class PolinaCounter : public BaseCounter {
public:
  void Increment(float &value_) override {
    //value_ += 0.1;
    elements_.push_back(value_);

  }
  float GetValue() const override {
        float value_ = 0.;
        float s = 0.0, c = 0.0, t;
        for (float x : elements_) {
             s = TwoSum(t, s, x);
             c += t;
        }
        value_ = s + c;

    return static_cast<float>(value_);
  }
  std::string GetName() override {
    return "Polina's algorithm";
  }

private:
  vector<float> elements_;
  float value_ = 0.0;
  float TwoSum(float &t, float a, float b) const {
    float s = a + b;
    float bs = s - a;
    float as = s - bs;
    t = (b - bs) + (a - as);
    return s;
}
};
//scoring by Kahan's algorithm
class KahanCounter : public BaseCounter {
public:
  void Increment(float &value_) override {
    float y = value_ - error_;
    float t = sum_ + y;
    error_ = (t - sum_) - y;
    sum_ = t;

  }
  float GetValue() const override {

    return static_cast<float>(sum_);
  }
  std::string GetName() override {
    return "Kahan algorithm";
  }

private:
  float sum_ = 0.0;
  float error_ = 0.0;

};

//interface for creation of scorers object

class CounterFactory {
public:
  virtual std::unique_ptr<BaseCounter> Create() const = 0;
};

// factory class for each scorer

class IntCounterFactory : public CounterFactory {
public:
  std::unique_ptr<BaseCounter> Create() const override {
    return std::make_unique<IntCounter>();
  }
};

class PolinaCounterFactory : public CounterFactory {
public:
  std::unique_ptr<BaseCounter> Create() const override {
    return std::make_unique<PolinaCounter>();
  }
};

class NikitaCounterFactory : public CounterFactory {
public:
  std::unique_ptr<BaseCounter> Create() const override {
    return std::make_unique<NikitaCounter>();
  }
};

class KahanCounterFactory : public CounterFactory {
public:
  std::unique_ptr<BaseCounter> Create() const override {
    return std::make_unique<KahanCounter>();
  }
};


/*
CounterFactory* factory = ... ;
auto counter = factory->Create();
counter->Increment(); 
int value = counter->GetValue();
*/
