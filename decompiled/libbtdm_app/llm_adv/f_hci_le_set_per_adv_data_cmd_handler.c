/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_adv.o -> f_hci_le_set_per_adv_data_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_per_adv_data_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  ushort uVar6;
  undefined2 uVar7;
  int iVar8;
  void *__dest;
  undefined4 uVar9;
  uint uVar10;
  char cVar11;
  int iVar12;
  code *pcVar13;
  uint uVar14;
  uint uStack_3c;
  undefined2 uStack_38;
  undefined2 uStack_36;
  undefined2 uStack_34;
  undefined2 uStack_32;
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L492:
    uVar9 = 0xc;
    goto _L490;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  if (0xef < *param_1) goto _L493;
  iVar8 = (**(code **)(_r_ip_funcs_p + 0x544))(0,*(code **)(_r_ip_funcs_p + 0x544));
  uVar9 = 0x42;
  if (iVar8 == 0xff) goto _L490;
  iVar5 = *(int *)(_p_llm_env + 8);
  uVar14 = (uint)*(byte *)(iVar5 + iVar8 * 0x44 + 0x3d);
  if (uVar14 == 0xff) goto _L492;
  bVar1 = param_1[1];
  if ((3 < bVar1) || (uVar10 = (uint)param_1[2], 0xfc < uVar10)) {
_L493:
    uVar9 = 0x12;
    goto _L490;
  }
  if (bVar1 != 3) {
    if (uVar10 == 0) goto _L493;
    if (*(char *)(uVar14 * 0x44 + iVar5 + 0x40) == '\f') goto _L492;
  }
  iVar3 = uVar14 * 0x44;
  iVar5 = iVar5 + iVar3;
  if ((uint)*(ushort *)(iVar5 + 0x30) < *(ushort *)(iVar5 + 0x2e) + uVar10) {
    if (*(short *)(iVar5 + 0x2c) != 0) {
      (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
      *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x2c) = 0;
    }
_L497:
    uVar9 = 7;
  }
  else {
    if ((bVar1 & 0xfd) == 1) {
      if (*(short *)(iVar5 + 0x2c) != 0) {
        (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
        iVar5 = *(int *)(_p_llm_env + 8) + iVar3;
        *(undefined2 *)(iVar5 + 0x2e) = 0;
      }
      if (param_1[1] == 3) {
        uVar6 = (ushort)param_1[2];
        if (uVar6 != 0) {
          pcVar13 = *(code **)(_r_ip_funcs_p + 0xd4);
          goto _L535;
        }
        uVar7 = 0;
        bVar2 = true;
      }
      else {
        uVar6 = *(ushort *)(iVar5 + 0x30);
        pcVar13 = *(code **)(_r_ip_funcs_p + 0xd4);
_L535:
        uVar7 = (*pcVar13)(uVar6,pcVar13);
        bVar2 = false;
      }
      iVar12 = _p_llm_env;
      *(undefined2 *)(iVar5 + 0x2c) = uVar7;
      if ((*(short *)(*(int *)(iVar12 + 8) + iVar3 + 0x2c) == 0) && (!bVar2)) goto _L497;
    }
    bVar1 = param_1[2];
    if (bVar1 != 0) {
      iVar5 = *(int *)(_p_llm_env + 8) + iVar3;
      __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                 (*(short *)(iVar5 + 0x2c) + *(short *)(iVar5 + 0x2e),
                                  *(code **)(_r_plf_funcs_p + 0xbc));
      memcpy(__dest,param_1 + 3,(uint)bVar1);
      iVar5 = *(int *)(_p_llm_env + 8) + iVar3;
      *(ushort *)(iVar5 + 0x2e) = *(short *)(iVar5 + 0x2e) + (ushort)param_1[2];
    }
    if ((byte)(param_1[1] - 2) < 2) {
      iVar5 = *(int *)(_p_llm_env + 8) + iVar3;
      if (*(char *)(iVar5 + 0x40) == '\f') {
        (**(code **)(_r_ip_funcs_p + 0x2d8))
                  (uVar14,*(undefined1 *)(iVar5 + 0x2e),*(undefined2 *)(iVar5 + 0x2c),
                   *(code **)(_r_ip_funcs_p + 0x2d8));
      }
      else if (*(short *)(iVar5 + 0x28) != 0) {
        (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
      }
      iVar12 = *(int *)(_p_llm_env + 8);
      piVar4 = (int *)(iVar3 + iVar12);
      iVar5 = piVar4[0xb];
      piVar4[0xb] = 0;
      piVar4[10] = iVar5;
      if ((_bt_rf_coex_hooks_p != 0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
        iVar8 = *(int *)(iVar12 + iVar8 * 0x44);
        uStack_3c = (uint)*(ushort *)(*piVar4 + 4);
        uStack_36 = 0;
        uStack_34 = 0;
        uStack_32 = 0;
        uStack_38 = *(undefined2 *)((int)piVar4 + 0x2e);
        if ((*(byte *)(iVar8 + 0x17) < 3) || (iVar5 = lld_phy_coded_500k_get(), iVar5 == 0)) {
          cVar11 = *(char *)(iVar8 + 0x17) + -1;
        }
        else {
          cVar11 = *(char *)(iVar8 + 0x17);
        }
        uStack_36 = CONCAT11(uStack_36._1_1_,cVar11);
        (**(code **)(_bt_rf_coex_hooks_p + 4))
                  (uVar14,4,&uStack_3c,*(code **)(_bt_rf_coex_hooks_p + 4));
      }
    }
    uVar9 = 0;
  }
_L490:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar9,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

