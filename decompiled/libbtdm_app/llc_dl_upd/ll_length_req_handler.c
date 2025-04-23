/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_dl_upd.o -> ll_length_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ll_length_req_handler(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(1,*(code **)(_r_ip_funcs_p + 0x678));
  if (iVar1 == 0) {
    uVar2 = 0x20;
    if (((0x1a < *(ushort *)(param_2 + 2)) && (0x1a < *(ushort *)(param_2 + 6))) &&
       (0x147 < *(ushort *)(param_2 + 4))) {
      if ((((ushort)(*(short *)(param_2 + 8) - 0x148U) < 0x4149) &&
          (*(ushort *)(param_2 + 2) < 0xfc)) &&
         ((*(ushort *)(param_2 + 6) < 0xfc && (*(ushort *)(param_2 + 4) < 0x4291)))) {
        (**(code **)(_r_ip_funcs_p + 0x5d8))(param_1,*(code **)(_r_ip_funcs_p + 0x5d8));
        uVar2 = 0;
      }
    }
  }
  else {
    uVar2 = 0x24;
  }
  return uVar2;
}

