/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> ble_log_simple_output.o -> r_ble_log_simple_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_ble_log_simple_init(int param_1)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  _ble_log_env = (void *)(**(code **)(_r_osi_funcs_p + 0x74))
                                   (0x20,*(code **)(_r_osi_funcs_p + 0x74));
  if (_ble_log_env == (void *)0x0) {
    uVar4 = 0xffffffff;
  }
  else {
    memset(_ble_log_env,0,0x18);
    pvVar1 = _ble_log_env;
    *(undefined4 *)((int)_ble_log_env + 8) = 0x10000;
    *(undefined1 *)((int)pvVar1 + 0x14) = 1;
    *(undefined4 *)((int)pvVar1 + 0x18) = 0xffff;
    *(undefined **)((int)pvVar1 + 0x10) = &r_ble_log_filter_callback;
    iVar3 = _r_osi_funcs_p;
    *(int *)((int)pvVar1 + 4) = param_1;
    uVar4 = (**(code **)(iVar3 + 0x74))(0x40,*(code **)(iVar3 + 0x74));
    pvVar2 = _ble_log_env;
    *(undefined4 *)((int)pvVar1 + 0x1c) = uVar4;
    if (*(void **)((int)pvVar2 + 0x1c) == (void *)0x0) {
      r_ble_log_simple_deinit();
      uVar4 = 0xfffffffe;
    }
    else {
      memset(*(void **)((int)pvVar2 + 0x1c),0xff,0x40);
      uVar4 = 0;
    }
  }
  return uVar4;
}

