/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_controller_deinit_internal
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
  iVar2 = r_btdm_vnd_ol_task_env_get();
  if (*(int *)(iVar2 + 8) != 0) {
    pcVar1 = *(code **)(_r_osi_funcs_p + 0x28);
    iVar2 = r_btdm_vnd_ol_task_env_get();
    (*pcVar1)(*(undefined4 *)(iVar2 + 8));
    iVar2 = r_btdm_vnd_ol_task_env_get();
    *(undefined4 *)(iVar2 + 8) = 0;
  }
  if (_g_rw_schd_queue != 0) {
    (**(code **)(_r_osi_funcs_p + 0x50))(*(code **)(_r_osi_funcs_p + 0x50));
    _g_rw_schd_queue = 0;
  }
  r_intc_deinit();
  r_ble_log_internal_x3(0x40c80222,_r_ip_funcs_p,_r_plf_funcs_p,_btdm_env_p);
  r_lld_env_deinit();
  r_llm_env_deinit();
  r_ble_util_buf_env_deinit();
  r_hci_tl_env_deinit();
  if (sdk_cfg_priv_opts != '\0') {
    r_flash_env_deinit();
  }
  if (_btdm_env_p != (int *)0x0) {
    if (*_btdm_env_p != 0) {
      (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
      *_btdm_env_p = 0;
    }
    if (_btdm_env_p[2] != 0) {
      (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
      _btdm_env_p[2] = 0;
    }
    if (_btdm_env_p[4] != 0) {
      (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
      _btdm_env_p[4] = 0;
    }
    if (_btdm_env_p[6] != 0) {
      (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
      _btdm_env_p[6] = 0;
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
  return;
}

