/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ble_log_async_output.o -> r_ble_log_async_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_log_async_deinit(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  
  if (_ble_log_env != 0) {
    (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
    _ble_log_env = 0;
  }
  if (_ble_log_async_env != (undefined1 *)0x0) {
    iVar2 = *(int *)(_ble_log_async_env + 0xc);
    puVar4 = _ble_log_async_env;
    if (iVar2 != 0) {
      iVar1 = 0;
      do {
        iVar3 = *(int *)(iVar2 + iVar1);
        if (iVar3 != 0) {
          if (*(int *)(iVar3 + 0x14) != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
            iVar3 = *(int *)(*(int *)(_ble_log_async_env + 0xc) + iVar1);
            *(undefined4 *)(iVar3 + 0x14) = 0;
          }
          (**(code **)(_r_osi_funcs_p + 0x7c))(iVar3,*(code **)(_r_osi_funcs_p + 0x7c));
          iVar2 = *(int *)(_ble_log_async_env + 0xc);
          *(undefined4 *)(iVar2 + iVar1) = 0;
        }
        iVar1 = iVar1 + 4;
      } while (iVar1 != 0xc);
      (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
      puVar4 = _ble_log_async_env;
      *(undefined4 *)(_ble_log_async_env + 0xc) = 0;
    }
    if (*(int *)(puVar4 + 8) != 0) {
      (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
      puVar4 = _ble_log_async_env;
      *(undefined4 *)(_ble_log_async_env + 8) = 0;
    }
    if (*(int *)(puVar4 + 4) != 0) {
      (**(code **)(_r_osi_funcs_p + 0x68))(*(code **)(_r_osi_funcs_p + 0x68));
      puVar4 = _ble_log_async_env;
      *_ble_log_async_env = 0;
      *(undefined4 *)(puVar4 + 4) = 0;
    }
    (**(code **)(_r_osi_funcs_p + 0x7c))(puVar4,*(code **)(_r_osi_funcs_p + 0x7c));
    _ble_log_async_env = (undefined1 *)0x0;
  }
  return;
}

