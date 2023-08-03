/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
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
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  byte *pbVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  
  if ((*(ushort *)(p_lld_cca + 4) & 0x10) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00010c96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x9bc))();
    return;
  }
  iVar2 = *(int *)(p_lld_cca + 0x28);
  bVar1 = *(byte *)(p_lld_cca + 8);
  if ((*(ushort *)(p_lld_cca + 4) & 4) != 0) {
    (**(code **)(_r_ip_funcs_p + 0x9a4))(*(code **)(_r_ip_funcs_p + 0x9a4));
  }
  uVar4 = 1;
  UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x994);
  pbVar3 = (byte *)(iVar2 + (uint)bVar1 * 0xc);
  bVar1 = *pbVar3;
  if ((bVar1 & 4) != 0) goto _L190;
  if ((bVar1 & 2) == 0) {
_L177:
    if ((bVar1 & 1) != 0) goto _L179;
    (*UNRECOVERED_JUMPTABLE)(1);
  }
  else {
    uVar6 = (uint)*(ushort *)(p_lld_cca + 0x12) << 1;
    uVar5 = (uint)*(byte *)(p_lld_cca + 0x25) * 0x280;
    if (uVar6 < uVar5) {
      uVar6 = uVar5;
    }
    if ((param_1 - *(int *)(pbVar3 + 4) & 0xfffffffU) < uVar6) goto _L177;
    *pbVar3 = bVar1 & 0xfd | 1;
_L179:
    (*UNRECOVERED_JUMPTABLE)(0);
    *(uint *)(pbVar3 + 4) = (rwip_prog_delay - 1) + param_1;
    *pbVar3 = *pbVar3 & 0xf7;
  }
  if ((*(ushort *)(p_lld_cca + 4) & 2) == 0) {
    return;
  }
  uVar4 = *(undefined1 *)(p_lld_cca + 8);
  UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x9a8);
_L190:
                    /* WARNING: Could not recover jumptable at 0x00010d58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar4);
  return;
}

