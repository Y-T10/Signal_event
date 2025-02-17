#pragma once

#include<algorithm>
#include<boost/noncopyable.hpp>
#include<csignal>
#include<vector>
#include<functional>

class SigEvent : private boost::noncopyable {
    public:
    /// コンストラクタ
    SigEvent() noexcept;
    /// デストラクタ
    ~SigEvent() = default;

    /// @brief 補足するシグナルを設定する
    /// @param sigs 補足するシグナルの一覧
    /// @return 設定の成否
    const bool set_signal(const std::vector<int>& sigs);

    /// @brief シグナルを処理する
    /// @param handler シグナルに対する処理
    void handle_signal(const std::function<void(const int)>& handler);

    /// @brief 補足したシグナルを返す
    /// @return 0ならばシグナルはなし．0より大きければシグナル．
    const int get_signal();

    private:
    /// 補足するシグナルのマスク
    sigset_t m_sigMask;
};