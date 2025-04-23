/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_con_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_con_start(int param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar4;
  uint uVar5;
  
  if ((*(ushort *)(p_lld_cca + 4) & 0x10) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00010c90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x9bc))(*(code **)(_r_ip_funcs_p + 0x9bc));
    return;
  }
  iVar2 = *(int *)(p_lld_cca + 0x28);
  bVar1 = *(byte *)(p_lld_cca + 8);
  if ((*(ushort *)(p_lld_cca + 4) & 4) != 0) {
    (**(code **)(_r_ip_funcs_p + 0x9a4))(*(code **)(_r_ip_funcs_p + 0x9a4));
  }
  UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x994);
  pbVar3 = (byte *)(iVar2 + (uint)bVar1 * 0xc);
  bVar1 = *pbVar3;
  if ((bVar1 & 4) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00010cd6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(1);
    return;
  }
  if ((bVar1 & 2) == 0) {
_L175:
    if ((bVar1 & 1) == 0) {
      (*UNRECOVERED_JUMPTABLE)(1);
      goto _L179;
    }
  }
  else {
    uVar4 = (uint)*(byte *)(p_lld_cca + 0x25) * 0x280;
    uVar5 = (uint)*(ushort *)(p_lld_cca + 0x12) << 1;
    if (uVar5 < uVar4) {
      uVar5 = uVar4;
    }
    if ((param_1 - *(int *)(pbVar3 + 4) & 0xfffffffU) < uVar5) goto _L175;
    *pbVar3 = bVar1 & 0xfd | 1;
  }
  (*UNRECOVERED_JUMPTABLE)(0);
  *(uint *)(pbVar3 + 4) = (rwip_prog_delay - 1) + param_1;
  *pbVar3 = *pbVar3 & 0xf7;
_L179:
  if ((*(ushort *)(p_lld_cca + 4) & 2) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00010d58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x9a8))
              (*(undefined1 *)(p_lld_cca + 8),*(code **)(_r_ip_funcs_p + 0x9a8));
    return;
  }
  return;
}

