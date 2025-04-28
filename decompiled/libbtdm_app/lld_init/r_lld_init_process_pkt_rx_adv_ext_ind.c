/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  int iVar11;
  uint uStack_24;
  
  iVar11 = *(int *)(_lld_init_env + param_1 * 4);
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar10 = (uint)bVar1 * 0x14;
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = *(ushort *)(iVar10 + 0x10 + iVar3);
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  if ((*(ushort *)(iVar10 + 4 + iVar3) & 0xf) != 7) {
                    /* WARNING: Could not recover jumptable at 0x000109e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x2bf,*(code **)(_r_plf_funcs_p + 8));
    return;
  }
  *(undefined1 *)(iVar11 + 0x3d) = 0;
  iVar3 = 0;
  if ((uVar2 & 0x100) != 0) {
    iVar3 = 6;
    pvVar4 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(param_2,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    memcpy((void *)(iVar11 + 0x32),pvVar4,6);
  }
  if ((uVar2 & 0x200) != 0) {
    iVar3 = iVar3 + 6;
  }
  if ((uVar2 & 0x400) != 0) {
    iVar3 = iVar3 + 1;
  }
  if ((uVar2 & 0x1800) != 0x1800) {
    if ((uVar2 >> 0xb & 1) != 0) {
      uVar8 = param_2 + iVar3;
      iVar3 = iVar3 + 2;
      puVar5 = (undefined2 *)
               (**(code **)(_r_plf_funcs_p + 0xbc))
                         (uVar8 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar11 + 0x3a) = *puVar5;
    }
    goto _L85;
  }
  puVar5 = (undefined2 *)
           (**(code **)(_r_plf_funcs_p + 0xbc))
                     (param_2 + iVar3 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar11 + 0x38) = *puVar5;
  pvVar4 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                             (iVar3 + 2 + param_2 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(&uStack_24,pvVar4,3);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  if ((*(ushort *)(iVar10 + 2 + iVar6) >> 9 & 1) == 0) {
    if ((uStack_24 >> 0x15 & 7) < 3) {
      iVar10 = (**(code **)(_r_ip_funcs_p + 0x224))
                         (iVar11 + 0x40,(uint)bVar1,*(code **)(_r_ip_funcs_p + 0x224));
      uVar9 = 1;
      if (iVar10 != 0) goto _L109;
    }
  }
  else {
    uVar9 = 2;
_L109:
    *(undefined1 *)(iVar11 + 0x3d) = uVar9;
  }
  iVar3 = iVar3 + 5;
_L85:
  if ((uVar2 & 0x2000) != 0) {
    iVar3 = iVar3 + 0x12;
  }
  if ((uVar2 & 0x4000) != 0) {
    puVar7 = (undefined1 *)
             (**(code **)(_r_plf_funcs_p + 0xbc))
                       (param_2 + iVar3 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined1 *)(iVar11 + 0x3c) = *puVar7;
  }
  return;
}

