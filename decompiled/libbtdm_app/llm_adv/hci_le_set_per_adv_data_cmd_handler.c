/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_adv.o -> hci_le_set_per_adv_data_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_per_adv_data_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  ushort uVar5;
  undefined2 uVar6;
  int iVar7;
  void *__dest;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  char cVar11;
  code *pcVar12;
  int iVar13;
  uint uVar14;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  iVar7 = _r_ip_funcs_p;
  if (*(char *)(iVar8 + 0x18) == '\0') {
    (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,0xc,*(code **)(_r_ip_funcs_p + 0x4b8));
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L492:
    uVar9 = 0xc;
    goto _L490;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  if (0xef < *param_1) goto _L493;
  iVar7 = (**(code **)(iVar7 + 0x544))(0,*(code **)(iVar7 + 0x544));
  uVar9 = 0x42;
  if (iVar7 == 0xff) goto _L490;
  iVar8 = *(int *)(_p_llm_env + 8);
  uVar14 = (uint)*(byte *)(iVar8 + iVar7 * 0x44 + 0x3d);
  if (uVar14 == 0xff) goto _L492;
  bVar1 = param_1[1];
  if ((3 < bVar1) || (uVar10 = (uint)param_1[2], 0xfc < uVar10)) {
_L493:
    uVar9 = 0x12;
    goto _L490;
  }
  if (bVar1 != 3) {
    if (uVar10 == 0) goto _L493;
    if (*(char *)(uVar14 * 0x44 + iVar8 + 0x40) == '\f') goto _L492;
  }
  iVar3 = uVar14 * 0x44;
  iVar8 = iVar8 + iVar3;
  if ((uint)*(ushort *)(iVar8 + 0x30) < *(ushort *)(iVar8 + 0x2e) + uVar10) {
    if (*(short *)(iVar8 + 0x2c) != 0) {
      (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
      *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x2c) = 0;
    }
_L533:
    uVar9 = 7;
  }
  else {
    if ((bVar1 & 0xfd) == 1) {
      if (*(short *)(iVar8 + 0x2c) != 0) {
        (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
        *(undefined2 *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x2e) = 0;
      }
      iVar8 = *(int *)(_p_llm_env + 8) + iVar3;
      if (param_1[1] == 3) {
        uVar5 = (ushort)param_1[2];
        if (uVar5 != 0) {
          pcVar12 = *(code **)(_r_ip_funcs_p + 0xd4);
          goto _L532;
        }
        uVar6 = 0;
        bVar2 = true;
      }
      else {
        uVar5 = *(ushort *)(iVar8 + 0x30);
        pcVar12 = *(code **)(_r_ip_funcs_p + 0xd4);
_L532:
        uVar6 = (*pcVar12)(uVar5,pcVar12);
        bVar2 = false;
      }
      iVar13 = _p_llm_env;
      *(undefined2 *)(iVar8 + 0x2c) = uVar6;
      if ((*(short *)(*(int *)(iVar13 + 8) + iVar3 + 0x2c) == 0) && (!bVar2)) goto _L533;
    }
    bVar1 = param_1[2];
    if (bVar1 != 0) {
      iVar8 = *(int *)(_p_llm_env + 8) + iVar3;
      __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                 (*(short *)(iVar8 + 0x2c) + *(short *)(iVar8 + 0x2e),
                                  *(code **)(_r_plf_funcs_p + 0xbc));
      memcpy(__dest,param_1 + 3,(uint)bVar1);
      iVar8 = *(int *)(_p_llm_env + 8) + iVar3;
      *(ushort *)(iVar8 + 0x2e) = *(short *)(iVar8 + 0x2e) + (ushort)param_1[2];
    }
    if ((byte)(param_1[1] - 2) < 2) {
      iVar8 = *(int *)(_p_llm_env + 8) + iVar3;
      if (*(char *)(iVar8 + 0x40) == '\f') {
        (**(code **)(_r_ip_funcs_p + 0x2d8))
                  (uVar14,*(undefined1 *)(iVar8 + 0x2e),*(undefined2 *)(iVar8 + 0x2c),
                   *(code **)(_r_ip_funcs_p + 0x2d8));
      }
      else if (*(short *)(iVar8 + 0x28) != 0) {
        (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
      }
      iVar13 = *(int *)(_p_llm_env + 8);
      piVar4 = (int *)(iVar3 + iVar13);
      iVar8 = piVar4[0xb];
      piVar4[0xb] = 0;
      piVar4[10] = iVar8;
      if ((_bt_rf_coex_hooks_p != 0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
        iVar7 = *(int *)(iVar13 + iVar7 * 0x44);
        uStack_3c = (uint)*(ushort *)(*piVar4 + 4);
        uStack_34 = 0;
        uStack_38 = (uint)*(ushort *)((int)piVar4 + 0x2e);
        if ((*(byte *)(iVar7 + 0x17) < 3) || (iVar8 = lld_phy_coded_500k_get(), iVar8 == 0)) {
          cVar11 = *(char *)(iVar7 + 0x17) + -1;
        }
        else {
          cVar11 = *(char *)(iVar7 + 0x17);
        }
        uStack_38._0_3_ = CONCAT12(cVar11,(undefined2)uStack_38);
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

