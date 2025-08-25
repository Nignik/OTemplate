namespace Otac
{
  template <typename T>
  class ScopedPtr
  {
  public:
    explicit ScopedPtr(T *p = nullptr)
        : ptr_{p}
    {
    }

    template <typename... Args>
    explicit ScopedPtr(Args &&...args)
        : ptr_{new T{std::forward<Args>(args)...}}
    {
    }

    ~ScopedPtr()
    {
      delete ptr_;
    }

    ScopedPtr(const ScopedPtr &) = delete;
    ScopedPtr &operator=(const ScopedPtr &) = delete;

    ScopedPtr(ScopedPtr &&other) noexcept : ptr_(other.ptr_)
    {
      other.ptr_ = nullptr;
    }

    ScopedPtr &operator=(ScopedPtr &&other) noexcept
    {
      if (this != &other)
      {
        delete ptr_;
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
      }
      return *this;
    }

    T &operator*() const { return *ptr_; }
    T *operator->() const { return ptr_; }
    T *Get() const { return ptr_; }

    T* Release()
    {
      T* temp = ptr_;
      ptr_ = nullptr;
      return temp;
    }

  private:
    T *ptr_;
  };
}