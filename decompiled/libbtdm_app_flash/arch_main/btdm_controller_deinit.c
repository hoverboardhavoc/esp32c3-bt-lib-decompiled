/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_controller_deinit
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
  int *piVar3;
  
  iVar2 = r_sdk_config_get_opts();
  if (*(char *)(iVar2 + 0xc) != '\0') {
    btdm_controller_disable();
  }
  r_btdm_task_post(8,0,0,1);
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
    piVar3 = _btdm_env_p;
    if (_btdm_env_p[9] != 0) {
      (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
      piVar3 = _btdm_env_p;
      _btdm_env_p[9] = 0;
    }
    (**(code **)(_r_osi_funcs_p + 0x7c))(piVar3,*(code **)(_r_osi_funcs_p + 0x7c));
    _btdm_env_p = (int *)0x0;
  }
  return;
}

