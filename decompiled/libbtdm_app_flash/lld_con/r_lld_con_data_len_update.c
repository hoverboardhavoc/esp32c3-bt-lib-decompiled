/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_data_len_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
r_lld_con_data_len_update
          (int param_1,undefined2 param_2,undefined4 param_3,undefined2 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  uVar2 = 0xc;
  if (iVar1 != 0) {
    iVar3 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar3 + 0x28) & 0x20) != 0) {
      iVar3 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar3 + 0x2c) < 3) {
        r_ble_log_internal_x3(0x40a30007,param_1,param_3,param_5);
      }
    }
    *(short *)(iVar1 + 0x86) = (short)param_3;
    *(undefined2 *)(iVar1 + 0x88) = param_2;
    *(undefined2 *)(iVar1 + 0x8a) = param_4;
    r_lld_con_evt_time_update_eco(param_1);
    r_lld_con_tx_len_update(param_1,*(undefined1 *)(iVar1 + 0x94),*(undefined4 *)(iVar1 + 100));
    uVar2 = 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar2;
}

