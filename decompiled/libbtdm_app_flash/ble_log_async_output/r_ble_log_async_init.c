/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> ble_log_async_output.o -> r_ble_log_async_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_ble_log_async_init(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  code *pcVar5;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  iVar3 = r_ble_log_async_env_init(param_3,param_4);
  if (iVar3 == 0) {
    _ble_log_env = (undefined1 *)
                   (**(code **)(_r_osi_funcs_p + 0x74))(0x20,*(code **)(_r_osi_funcs_p + 0x74));
    if (_ble_log_env == (undefined1 *)0x0) {
      uVar2 = 2;
    }
    else {
      memset(_ble_log_env,0,0x20);
      puVar4 = _ble_log_env;
      *_ble_log_env = 0;
      *(int *)(puVar4 + 4) = param_1;
      *(code **)(puVar4 + 8) = r_ble_log_async_output;
      *(undefined4 *)(puVar4 + 0xc) = 0;
      if (param_2 != 0) {
        pcVar5 = *(code **)(_r_osi_funcs_p + 100);
        puVar4 = _ble_log_async_env + 4;
        iVar3 = r_sdk_config_get_opts();
        iVar3 = (*pcVar5)(ble_log_async_task_func,"ble_ctrl_log",0xa00,0,0,puVar4,
                          *(undefined1 *)(iVar3 + 0xb));
        if (iVar3 == -1) {
          uVar2 = 3;
          *_ble_log_async_env = 0;
          goto _L186;
        }
        *_ble_log_async_env = 1;
      }
      puVar4 = _ble_log_env;
      _ble_log_env[0x14] = 1;
      *(undefined4 *)(puVar4 + 0x18) = 0xffff;
      *(undefined **)(puVar4 + 0x10) = &r_ble_log_filter_callback;
      uVar2 = (**(code **)(_r_osi_funcs_p + 0x74))(0x40,*(code **)(_r_osi_funcs_p + 0x74));
      puVar1 = _ble_log_env;
      *(undefined4 *)(puVar4 + 0x1c) = uVar2;
      if (*(void **)(puVar1 + 0x1c) != (void *)0x0) {
        memset(*(void **)(puVar1 + 0x1c),0xff,0x40);
        return 0;
      }
      uVar2 = 4;
    }
  }
  else {
    uVar2 = 1;
  }
_L186:
  r_ble_log_async_deinit();
  return uVar2;
}

