/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_process_pkt_rx_adv_ext_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_process_pkt_rx_adv_ext_ind(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  void *pvVar4;
  undefined2 *puVar5;
  int iVar6;
  undefined1 *puVar7;
  uint uVar8;
  undefined1 uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uStack_24;
  
  iVar12 = *(int *)(_lld_init_env + param_1 * 4);
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar10 = (uint)bVar1 * 0x14;
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = *(ushort *)(iVar10 + 0x10 + iVar3);
  uVar11 = (uint)uVar2;
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  if ((*(ushort *)(iVar10 + 4 + iVar3) & 0xf) != 7) {
                    /* WARNING: Could not recover jumptable at 0x0001099a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x2bf,*(code **)(_r_plf_funcs_p + 8));
    return;
  }
  *(undefined1 *)(iVar12 + 0x3d) = 0;
  iVar3 = 0;
  if ((uVar2 & 0x100) != 0) {
    iVar3 = 6;
    pvVar4 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(param_2,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    memcpy((void *)(iVar12 + 0x32),pvVar4,6);
  }
  if ((uVar2 & 0x200) != 0) {
    iVar3 = iVar3 + 6;
  }
  iVar3 = iVar3 + (uint)((uVar2 & 0x400) != 0);
  if ((uVar11 & 0x1800) != 0x1800) {
    if ((int)(uVar11 << 0x14) < 0) {
      uVar8 = param_2 + iVar3;
      iVar3 = iVar3 + 2;
      puVar5 = (undefined2 *)
               (**(code **)(_r_plf_funcs_p + 0xbc))
                         (uVar8 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar12 + 0x3a) = *puVar5;
    }
    goto _L81;
  }
  puVar5 = (undefined2 *)
           (**(code **)(_r_plf_funcs_p + 0xbc))
                     (param_2 + iVar3 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar12 + 0x38) = *puVar5;
  pvVar4 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                             (iVar3 + 2 + param_2 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(&uStack_24,pvVar4,3);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  if ((*(ushort *)(iVar10 + 2 + iVar6) >> 9 & 1) == 0) {
    if ((uStack_24 >> 0x15 & 7) < 3) {
      iVar10 = (**(code **)(_r_ip_funcs_p + 0x224))
                         (iVar12 + 0x40,(uint)bVar1,*(code **)(_r_ip_funcs_p + 0x224));
      uVar9 = 1;
      if (iVar10 != 0) goto _L107;
    }
  }
  else {
    uVar9 = 2;
_L107:
    *(undefined1 *)(iVar12 + 0x3d) = uVar9;
  }
  iVar3 = iVar3 + 5;
_L81:
  if ((int)(uVar11 << 0x12) < 0) {
    iVar3 = iVar3 + 0x12;
  }
  if ((int)(uVar11 << 0x11) < 0) {
    puVar7 = (undefined1 *)
             (**(code **)(_r_plf_funcs_p + 0xbc))
                       (param_2 + iVar3 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined1 *)(iVar12 + 0x3c) = *puVar7;
  }
  return;
}

