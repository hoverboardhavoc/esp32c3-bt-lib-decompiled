/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  
  iVar2 = *(int *)(p_lld_cca + 0x28);
  bVar1 = *(byte *)(p_lld_cca + 8);
  if ((*(ushort *)(p_lld_cca + 4) & 0x10) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00010ca6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x9bc))(*(code **)(_r_ip_funcs_p + 0x9bc));
    return;
  }
  if ((*(ushort *)(p_lld_cca + 4) & 4) != 0) {
    (**(code **)(_r_ip_funcs_p + 0x9a4))(*(code **)(_r_ip_funcs_p + 0x9a4));
  }
  UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x994);
  pbVar3 = (byte *)(iVar2 + (uint)bVar1 * 0xc);
  bVar1 = *pbVar3;
  if ((bVar1 & 4) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00010cea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(1);
    return;
  }
  if ((bVar1 & 2) != 0) {
    uVar4 = (uint)*(byte *)(p_lld_cca + 0x25) * 0x280;
    uVar5 = (uint)*(ushort *)(p_lld_cca + 0x12) << 1;
    if (uVar5 < uVar4) {
      uVar5 = uVar4;
    }
    if (uVar5 <= (param_1 - *(int *)(pbVar3 + 4) & 0xfffffffU)) {
      *pbVar3 = bVar1 & 0xfd | 1;
    }
  }
  if ((*pbVar3 & 1) == 0) {
    (*UNRECOVERED_JUMPTABLE)(1);
  }
  else {
    (*UNRECOVERED_JUMPTABLE)(0);
    *(uint *)(pbVar3 + 4) = (rwip_prog_delay - 1) + param_1;
    *pbVar3 = *pbVar3 & 0xf7;
  }
  if ((*(ushort *)(p_lld_cca + 4) & 2) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00010d70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x9a8))
              (*(undefined1 *)(p_lld_cca + 8),*(code **)(_r_ip_funcs_p + 0x9a8));
    return;
  }
  return;
}

