/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  int iVar7;
  int iVar8;
  
  iVar8 = *(int *)(&lld_con_env + param_1 * 4);
  if (*(int *)(iVar8 + 0x30) == 0) {
    iVar7 = *(int *)(iVar8 + 0x28);
    *(int *)(iVar8 + 0x30) = iVar7;
    if (iVar7 != 0) {
      *(ushort *)(iVar8 + 0x82) = *(ushort *)(iVar7 + 6) & 0x3ff;
    }
  }
  bVar4 = false;
  if ((((*(ushort *)(iVar8 + 0x84) & 0x10) != 0) && (*(int **)(iVar8 + 0x30) != (int *)0x0)) &&
     (bVar4 = true, *(short *)(iVar8 + 0x82) == 0)) {
    bVar4 = **(int **)(iVar8 + 0x30) != 0;
  }
  iVar7 = *(int *)(iVar8 + 0x24);
  if ((iVar7 == 0) && (!bVar4)) {
    return;
  }
  if (*(char *)(iVar8 + 0x92) == '\x02') {
    bVar1 = *(byte *)(iVar8 + 0x91);
    bVar2 = *(byte *)(iVar8 + 0x8e);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar8 = ((bVar1 + 1 & 1) + (uint)bVar2 * 9 & 0xff) * 0xe;
    if (-1 < *(short *)(iVar7 + iVar8)) {
      iVar8 = iVar8 + 2;
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *(ushort *)(iVar7 + iVar8);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar7 + iVar8) = uVar3 & 0xffef | 0x10;
    }
    return;
  }
  uVar6 = 0x23;
  if (iVar7 != 0) {
    puVar5 = (undefined1 *)
             (**(code **)(_r_plf_funcs_p + 0xbc))
                       (*(undefined2 *)(iVar7 + 4),0x23,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar6 = *puVar5;
  }
                    /* WARNING: Could not recover jumptable at 0x000126d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x790))(param_1,uVar6);
  return;
}

