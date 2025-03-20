/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
  uint uVar3;
  int iVar4;
  void *pvVar5;
  undefined2 *puVar6;
  int iVar7;
  undefined1 *puVar8;
  uint uVar9;
  undefined1 uVar10;
  int iVar11;
  int iVar12;
  uint uStack_24;
  
  iVar12 = *(int *)(_lld_init_env + param_1 * 4);
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar11 = (uint)bVar1 * 0x14;
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = *(ushort *)(iVar4 + iVar11 + 0x10);
  uVar3 = (uint)uVar2;
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  if ((*(ushort *)(iVar4 + iVar11 + 4) & 0xf) != 7) {
                    /* WARNING: Could not recover jumptable at 0x000109fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",700);
    return;
  }
  *(undefined1 *)(iVar12 + 0x3d) = 0;
  iVar4 = 0;
  if ((uVar2 & 0x100) != 0) {
    iVar4 = 6;
    pvVar5 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(param_2,*(code **)(_r_plf_funcs_p + 0xbc))
    ;
    memcpy((void *)(iVar12 + 0x32),pvVar5,6);
  }
  if ((uVar2 & 0x200) != 0) {
    iVar4 = iVar4 + 6;
  }
  if ((uVar2 & 0x400) != 0) {
    iVar4 = iVar4 + 1;
  }
  if ((uVar3 & 0x1800) != 0x1800) {
    if ((int)(uVar3 << 0x14) < 0) {
      uVar9 = param_2 + iVar4;
      iVar4 = iVar4 + 2;
      puVar6 = (undefined2 *)
               (**(code **)(_r_plf_funcs_p + 0xbc))
                         (uVar9 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar12 + 0x3a) = *puVar6;
    }
    goto _L86;
  }
  puVar6 = (undefined2 *)
           (**(code **)(_r_plf_funcs_p + 0xbc))
                     (param_2 + iVar4 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar12 + 0x38) = *puVar6;
  pvVar5 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                             (iVar4 + 2 + param_2 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(&uStack_24,pvVar5,3);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  if ((*(ushort *)(iVar11 + 2 + iVar7) >> 9 & 1) == 0) {
    if ((uStack_24 >> 0x15 & 7) < 3) {
      iVar11 = (**(code **)(_r_ip_funcs_p + 0x224))
                         (iVar12 + 0x40,(uint)bVar1,*(code **)(_r_ip_funcs_p + 0x224));
      uVar10 = 1;
      if (iVar11 != 0) goto _L110;
    }
  }
  else {
    uVar10 = 2;
_L110:
    *(undefined1 *)(iVar12 + 0x3d) = uVar10;
  }
  iVar4 = iVar4 + 5;
_L86:
  if ((int)(uVar3 << 0x12) < 0) {
    iVar4 = iVar4 + 0x12;
  }
  if ((int)(uVar3 << 0x11) < 0) {
    puVar8 = (undefined1 *)
             (**(code **)(_r_plf_funcs_p + 0xbc))
                       (param_2 + iVar4 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined1 *)(iVar12 + 0x3c) = *puVar8;
  }
  return;
}

