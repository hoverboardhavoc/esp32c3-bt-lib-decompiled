/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app -> lld.o -> lld_le_pkt_err_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lld_le_pkt_err_set(uint param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  
  if (0xb < param_1) {
    (**(code **)(_r_plf_funcs_p + 0xc))(0xc,"lld.c",0x2cc,*(code **)(_r_plf_funcs_p + 0xc));
  }
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar1 = *(ushort *)(param_2 * 0x14 + 2 + iVar2);
  if ((uVar1 & 0xf) != 0) {
    if ((uVar1 & 1) != 0) {
      *(short *)(&lld_le_pkt_env + param_1) = *(short *)(&lld_le_pkt_env + param_1) + 1;
    }
    if ((uVar1 & 8) != 0) {
      *(short *)((int)&lld_le_pkt_env + param_1 * 4 + 2) =
           *(short *)((int)&lld_le_pkt_env + param_1 * 4 + 2) + 1;
    }
  }
  return;
}

