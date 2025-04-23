/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_tx_prog
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_tx_prog(int param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  undefined1 *puVar5;
  undefined1 uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  iVar9 = *(int *)(&lld_con_env + param_1 * 4);
  piVar7 = *(int **)(iVar9 + 0x30);
  if (piVar7 == (int *)0x0) {
    piVar7 = *(int **)(iVar9 + 0x28);
    *(int **)(iVar9 + 0x30) = piVar7;
    if (piVar7 != (int *)0x0) {
      *(ushort *)(iVar9 + 0x82) = *(ushort *)((int)piVar7 + 6) & 0x3ff;
    }
  }
  bVar4 = false;
  if ((((*(ushort *)(iVar9 + 0x84) & 0x10) != 0) && (piVar7 != (int *)0x0)) &&
     (bVar4 = true, *(short *)(iVar9 + 0x82) == 0)) {
    bVar4 = *piVar7 != 0;
  }
  iVar8 = *(int *)(iVar9 + 0x24);
  if ((iVar8 != 0) || (bVar4)) {
    if (*(char *)(iVar9 + 0x92) != '\x02') {
      uVar6 = 0x23;
      if (iVar8 != 0) {
        puVar5 = (undefined1 *)
                 (**(code **)(_r_plf_funcs_p + 0xbc))
                           (*(undefined2 *)(iVar8 + 4),0x23,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar6 = *puVar5;
      }
                    /* WARNING: Could not recover jumptable at 0x0001266c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 0x790))(param_1,uVar6,*(code **)(_r_ip_funcs_p + 0x790));
      return;
    }
    bVar1 = *(byte *)(iVar9 + 0x91);
    bVar2 = *(byte *)(iVar9 + 0x8e);
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar9 = ((bVar1 + 1 & 1) + (uint)bVar2 * 9 & 0xff) * 0xe;
    if (-1 < *(short *)(iVar8 + iVar9)) {
      iVar9 = iVar9 + 2;
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *(ushort *)(iVar8 + iVar9);
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar8 + iVar9) = uVar3 | 0x10;
    }
  }
  return;
}

