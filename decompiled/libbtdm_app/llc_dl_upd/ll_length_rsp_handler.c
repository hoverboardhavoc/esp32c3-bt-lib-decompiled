/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_dl_upd.o -> ll_length_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ll_length_rsp_handler(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  ushort uVar3;
  
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(0,*(code **)(_r_ip_funcs_p + 0x678));
  uVar1 = 0x24;
  if (iVar2 == 7) {
    uVar1 = 0x20;
    if ((((0x1a < *(ushort *)(param_2 + 2)) && (0x1a < *(ushort *)(param_2 + 6))) &&
        (0x147 < *(ushort *)(param_2 + 4))) && (0x147 < *(ushort *)(param_2 + 8))) {
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x674))(param_1,0,*(code **)(_r_ip_funcs_p + 0x674));
      uVar3 = *(ushort *)(iVar2 + 8);
      if (*(ushort *)(param_2 + 2) < *(ushort *)(iVar2 + 8)) {
        uVar3 = *(ushort *)(param_2 + 2);
      }
      *(ushort *)(iVar2 + 8) = uVar3;
      uVar3 = *(ushort *)(iVar2 + 10);
      if (*(ushort *)(param_2 + 4) < *(ushort *)(iVar2 + 10)) {
        uVar3 = *(ushort *)(param_2 + 4);
      }
      *(ushort *)(iVar2 + 10) = uVar3;
      uVar3 = *(ushort *)(iVar2 + 0xc);
      if (*(ushort *)(param_2 + 6) < *(ushort *)(iVar2 + 0xc)) {
        uVar3 = *(ushort *)(param_2 + 6);
      }
      *(ushort *)(iVar2 + 0xc) = uVar3;
      uVar3 = *(ushort *)(iVar2 + 0xe);
      if (*(ushort *)(param_2 + 8) < *(ushort *)(iVar2 + 0xe)) {
        uVar3 = *(ushort *)(param_2 + 8);
      }
      *(ushort *)(iVar2 + 0xe) = uVar3;
      uVar1 = 0;
    }
    (**(code **)(_r_ip_funcs_p + 0x5d4))(param_1,uVar1,*(code **)(_r_ip_funcs_p + 0x5d4));
  }
  return uVar1;
}

