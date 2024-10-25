/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_deinit_internal
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_controller_deinit_internal(void)

{
  code *pcVar1;
  int iVar2;
  
  if (_g_rw_init_sem != 0) {
    (**(code **)(_r_osi_funcs_p + 0x28))(*(code **)(_r_osi_funcs_p + 0x28));
    _g_rw_init_sem = 0;
  }
  if (_g_rw_controller_task_handle != 0) {
    (**(code **)(_r_osi_funcs_p + 0x68))(*(code **)(_r_osi_funcs_p + 0x68));
    _g_rw_controller_task_handle = 0;
  }
  if (_g_waking_sleeping_sem != 0) {
    (**(code **)(_r_osi_funcs_p + 0x28))(*(code **)(_r_osi_funcs_p + 0x28));
    _g_waking_sleeping_sem = 0;
  }
  if ((_r_plf_funcs_p != 0) &&
     (iVar2 = (**(code **)(_r_plf_funcs_p + 0xf8))(*(code **)(_r_plf_funcs_p + 0xf8)),
     *(int *)(iVar2 + 8) != 0)) {
    pcVar1 = *(code **)(_r_osi_funcs_p + 0x28);
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xf8))(*(code **)(_r_plf_funcs_p + 0xf8));
    (*pcVar1)(*(undefined4 *)(iVar2 + 8));
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xf8))(*(code **)(_r_plf_funcs_p + 0xf8));
    *(undefined4 *)(iVar2 + 8) = 0;
  }
  if (_g_rw_schd_queue != 0) {
    (**(code **)(_r_osi_funcs_p + 0x50))(*(code **)(_r_osi_funcs_p + 0x50));
    _g_rw_schd_queue = 0;
  }
  r_intc_deinit();
  if (_r_ip_funcs_p != 0) {
    (**(code **)(_r_ip_funcs_p + 0x240))(*(code **)(_r_ip_funcs_p + 0x240));
    (**(code **)(_r_ip_funcs_p + 0x4cc))(*(code **)(_r_ip_funcs_p + 0x4cc));
    (**(code **)(_r_ip_funcs_p + 0xe0))(*(code **)(_r_ip_funcs_p + 0xe0));
    (**(code **)(_r_ip_funcs_p + 0x40))(*(code **)(_r_ip_funcs_p + 0x40));
  }
  if ((_r_plf_funcs_p != 0) && (sdk_cfg_priv_opts != '\0')) {
    (**(code **)(_r_plf_funcs_p + 0x48))(*(code **)(_r_plf_funcs_p + 0x48));
  }
  if (_btdm_env_p != (int *)0x0) {
    if (*_btdm_env_p != 0) {
      (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
    }
    if (_btdm_env_p[2] != 0) {
      (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
    }
    if (_btdm_env_p[4] != 0) {
      (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
    }
    if (_btdm_env_p[6] != 0) {
      (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
    }
    if (_btdm_env_p[9] != 0) {
      (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
      _btdm_env_p[9] = 0;
    }
    if (_btdm_env_p != (int *)0x0) {
      (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
      _btdm_env_p = (int *)0x0;
    }
  }
  if (_r_plf_funcs_p != 0) {
    (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
    _r_plf_funcs_p = 0;
  }
  if (_r_modules_funcs_p != 0) {
    (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
    _r_modules_funcs_p = 0;
  }
  if (_r_ip_funcs_p != 0) {
    (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
    _r_ip_funcs_p = 0;
  }
  return;
}

