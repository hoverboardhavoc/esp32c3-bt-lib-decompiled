/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> ble_log_simple_output.o -> r_ble_log_simple_output
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_log_simple_output(size_t param_1,void *param_2,size_t param_3,void *param_4)

{
  int iVar1;
  
  iVar1 = param_3 + param_1 + 2;
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  **(undefined1 **)(_ble_log_async_env + 8) = (char)iVar1;
  *(char *)(*(int *)(_ble_log_async_env + 8) + 1) = (char)((uint)iVar1 >> 8);
  if (iVar1 < 0x12d) {
    memcpy((void *)(*(int *)(_ble_log_async_env + 8) + 2),param_2,param_1);
    memcpy((void *)(*(int *)(_ble_log_async_env + 8) + param_1 + 2),param_4,param_3);
  }
  (**(code **)(_ble_log_env + 4))
            (iVar1,*(undefined4 *)(_ble_log_async_env + 8),1,*(code **)(_ble_log_env + 4));
                    /* WARNING: Could not recover jumptable at 0x000100aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

