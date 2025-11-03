/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_data_len_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
r_lld_con_data_len_update(int param_1,undefined2 param_2,uint param_3,ushort param_4,uint param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  uVar2 = 0xc;
  if (iVar1 != 0) {
    *(ushort *)(iVar1 + 0x8a) = param_4;
    *(short *)(iVar1 + 0x86) = (short)param_3;
    *(undefined2 *)(iVar1 + 0x88) = param_2;
    r_lld_con_evt_time_update_eco(param_1);
    r_lld_con_tx_len_update(param_1,*(undefined1 *)(iVar1 + 0x94),*(undefined4 *)(iVar1 + 100));
    r_ble_log_internal_x3
              (0x40a30092,param_5 << 0x10 | param_3,(uint)param_4 << 0x10 | param_5,param_1);
    uVar2 = 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar2;
}

