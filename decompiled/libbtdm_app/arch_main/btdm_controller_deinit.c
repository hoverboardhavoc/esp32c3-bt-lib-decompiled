/*
 * Last changed at upstream commit 0698a0dac04e7762ec555dca86bbfa2a631cefa3
 * https://github.com/espressif/esp32c3-bt-lib/commit/0698a0dac04e7762ec555dca86bbfa2a631cefa3
 * Upstream date: 2024-03-26 14:09:42 +0800
 * Upstream subject: feat(ble/controller): Add coexist schm (bb95ac61)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_controller_deinit(void)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(char *)(iVar2 + 0xc) != '\0') {
    btdm_controller_disable();
  }
  (**(code **)(_r_plf_funcs_p + 0x28))(8,0,0,1,*(code **)(_r_plf_funcs_p + 0x28));
  (**(code **)(_r_osi_funcs_p + 0x34))(_g_rw_init_sem,10000,*(code **)(_r_osi_funcs_p + 0x34));
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
  if (_r_ip_funcs_p != 0) {
    (**(code **)(_r_ip_funcs_p + 0x240))(*(code **)(_r_ip_funcs_p + 0x240));
    (**(code **)(_r_ip_funcs_p + 0x4cc))(*(code **)(_r_ip_funcs_p + 0x4cc));
    (**(code **)(_r_ip_funcs_p + 0xe0))(*(code **)(_r_ip_funcs_p + 0xe0));
    (**(code **)(_r_ip_funcs_p + 0x40))(*(code **)(_r_ip_funcs_p + 0x40));
  }
  if (_r_plf_funcs_p != 0) {
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

