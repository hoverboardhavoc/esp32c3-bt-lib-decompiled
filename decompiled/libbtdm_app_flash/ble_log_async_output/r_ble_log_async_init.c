/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ble_log_async_output.o -> r_ble_log_async_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_ble_log_async_init(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  code *pcVar4;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  iVar2 = r_ble_log_async_env_init(param_3,param_4);
  if (iVar2 == 0) {
    _ble_log_env = (undefined1 *)
                   (**(code **)(_r_osi_funcs_p + 0x74))(0x10,*(code **)(_r_osi_funcs_p + 0x74));
    if (_ble_log_env == (undefined1 *)0x0) {
      uVar1 = 2;
    }
    else {
      memset(_ble_log_env,0,0x10);
      puVar3 = _ble_log_env;
      *_ble_log_env = 0;
      *(int *)(puVar3 + 4) = param_1;
      *(code **)(puVar3 + 8) = r_ble_log_async_output;
      *(undefined4 *)(puVar3 + 0xc) = 0;
      if (param_2 == 0) {
        return 0;
      }
      pcVar4 = *(code **)(_r_osi_funcs_p + 100);
      puVar3 = _ble_log_async_env + 4;
      iVar2 = r_sdk_config_get_opts();
      iVar2 = (*pcVar4)(ble_log_async_task_func,"ble_ctrl_log",0xa00,0,0,puVar3,
                        *(undefined1 *)(iVar2 + 0xb));
      if (iVar2 != -1) {
        *_ble_log_async_env = 1;
        return 0;
      }
      *_ble_log_async_env = 0;
      uVar1 = 3;
    }
  }
  else {
    uVar1 = 1;
  }
  r_ble_log_async_deinit();
  return uVar1;
}

