/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> ble_log_async_output.o -> r_ble_log_async_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_log_async_deinit(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  if (_ble_log_env != 0) {
    (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
    _ble_log_env = 0;
  }
  if (_ble_log_async_env != (undefined1 *)0x0) {
    if (*(int *)(_ble_log_async_env + 0xc) != 0) {
      iVar2 = 0;
      do {
        if (*(int *)(*(int *)(_ble_log_async_env + 0xc) + iVar2) != 0) {
          if (*(int *)(*(int *)(*(int *)(_ble_log_async_env + 0xc) + iVar2) + 0x14) != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
            *(undefined4 *)(*(int *)(*(int *)(_ble_log_async_env + 0xc) + iVar2) + 0x14) = 0;
          }
          (**(code **)(_r_osi_funcs_p + 0x7c))
                    (*(undefined4 *)(*(int *)(_ble_log_async_env + 0xc) + iVar2),
                     *(code **)(_r_osi_funcs_p + 0x7c));
          *(undefined4 *)(*(int *)(_ble_log_async_env + 0xc) + iVar2) = 0;
        }
        iVar2 = iVar2 + 4;
      } while (iVar2 != 0xc);
      (**(code **)(_r_osi_funcs_p + 0x7c))
                (*(undefined4 *)(_ble_log_async_env + 0xc),*(code **)(_r_osi_funcs_p + 0x7c));
      *(undefined4 *)(_ble_log_async_env + 0xc) = 0;
    }
    if (*(int *)(_ble_log_async_env + 8) != 0) {
      (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
      *(undefined4 *)(_ble_log_async_env + 8) = 0;
    }
    if (*(int *)(_ble_log_async_env + 4) != 0) {
      (**(code **)(_r_osi_funcs_p + 0x68))(*(code **)(_r_osi_funcs_p + 0x68));
      puVar1 = _ble_log_async_env;
      *_ble_log_async_env = 0;
      *(undefined4 *)(puVar1 + 4) = 0;
    }
    (**(code **)(_r_osi_funcs_p + 0x7c))(_ble_log_async_env,*(code **)(_r_osi_funcs_p + 0x7c));
    _ble_log_async_env = (undefined1 *)0x0;
  }
  return;
}

