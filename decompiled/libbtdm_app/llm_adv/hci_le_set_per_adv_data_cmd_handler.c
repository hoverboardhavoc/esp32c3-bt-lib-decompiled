/*
 * Last changed at upstream commit 27af69ccbb02f3b820436f47eaa0b1cd544edfbc
 * https://github.com/espressif/esp32c3-bt-lib/commit/27af69ccbb02f3b820436f47eaa0b1cd544edfbc
 * Upstream date: 2023-09-26 16:09:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(c8aa206)
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
  undefined4 uVar8;
  uint uVar9;
  char cVar10;
  int iVar11;
  code *pcVar12;
  uint uVar13;
  uint uStack_3c;
  undefined2 uStack_38;
  undefined2 uStack_36;
  undefined2 uStack_34;
  undefined2 uStack_32;
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L449:
    uVar8 = 0xc;
    goto _L447;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  if (0xef < *param_1) goto _L450;
  iVar7 = (**(code **)(_r_ip_funcs_p + 0x544))(0,*(code **)(_r_ip_funcs_p + 0x544));
  uVar8 = 0x42;
  if (iVar7 == 0xff) goto _L447;
  iVar11 = *(int *)(_p_llm_env + 8);
  uVar13 = (uint)*(byte *)(iVar11 + iVar7 * 0x44 + 0x3d);
  if (uVar13 == 0xff) goto _L449;
  bVar1 = param_1[1];
  if ((3 < bVar1) || (uVar9 = (uint)param_1[2], 0xfc < uVar9)) {
_L450:
    uVar8 = 0x12;
    goto _L447;
  }
  if (bVar1 != 3) {
    if (uVar9 == 0) goto _L450;
    if (*(char *)(uVar13 * 0x44 + iVar11 + 0x40) == '\f') goto _L449;
  }
  iVar3 = uVar13 * 0x44;
  iVar11 = iVar11 + iVar3;
  if ((uint)*(ushort *)(iVar11 + 0x30) < *(ushort *)(iVar11 + 0x2e) + uVar9) {
    if (*(short *)(iVar11 + 0x2c) != 0) {
      (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
      *(undefined4 *)(iVar3 + *(int *)(_p_llm_env + 8) + 0x2c) = 0;
    }
_L490:
    uVar8 = 7;
  }
  else {
    if ((bVar1 & 0xfd) == 1) {
      if (*(short *)(iVar11 + 0x2c) != 0) {
        (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
        *(undefined2 *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x2e) = 0;
      }
      iVar11 = *(int *)(_p_llm_env + 8) + iVar3;
      if (param_1[1] == 3) {
        uVar5 = (ushort)param_1[2];
        if (uVar5 != 0) {
          pcVar12 = *(code **)(_r_ip_funcs_p + 0xd4);
          goto _L489;
        }
        *(undefined2 *)(iVar11 + 0x2c) = 0;
        bVar2 = true;
      }
      else {
        uVar5 = *(ushort *)(iVar11 + 0x30);
        pcVar12 = *(code **)(_r_ip_funcs_p + 0xd4);
_L489:
        uVar6 = (*pcVar12)(uVar5,pcVar12);
        *(undefined2 *)(iVar11 + 0x2c) = uVar6;
        bVar2 = false;
      }
      if ((*(short *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x2c) == 0) && (!bVar2)) goto _L490;
    }
    bVar1 = param_1[2];
    if (bVar1 != 0) {
      iVar11 = *(int *)(_p_llm_env + 8) + iVar3;
      __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                 (*(short *)(iVar11 + 0x2c) + *(short *)(iVar11 + 0x2e),
                                  *(code **)(_r_plf_funcs_p + 0xbc));
      memcpy(__dest,param_1 + 3,(uint)bVar1);
      iVar11 = *(int *)(_p_llm_env + 8) + iVar3;
      *(ushort *)(iVar11 + 0x2e) = *(short *)(iVar11 + 0x2e) + (ushort)param_1[2];
    }
    if ((byte)(param_1[1] - 2) < 2) {
      iVar11 = *(int *)(_p_llm_env + 8) + iVar3;
      if (*(char *)(iVar11 + 0x40) == '\f') {
        (**(code **)(_r_ip_funcs_p + 0x2d8))
                  (uVar13,*(undefined1 *)(iVar11 + 0x2e),*(undefined2 *)(iVar11 + 0x2c),
                   *(code **)(_r_ip_funcs_p + 0x2d8));
      }
      else if (*(short *)(iVar11 + 0x28) != 0) {
        (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
      }
      iVar11 = *(int *)(_p_llm_env + 8);
      piVar4 = (int *)(iVar3 + iVar11);
      iVar3 = piVar4[0xb];
      piVar4[0xb] = 0;
      piVar4[10] = iVar3;
      if ((_bt_rf_coex_hooks_p != 0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
        iVar7 = *(int *)(iVar11 + iVar7 * 0x44);
        uStack_3c = (uint)*(ushort *)(*piVar4 + 4);
        uStack_36 = 0;
        uStack_34 = 0;
        uStack_32 = 0;
        uStack_38 = *(undefined2 *)((int)piVar4 + 0x2e);
        if ((*(byte *)(iVar7 + 0x17) < 3) || (iVar11 = lld_phy_coded_500k_get(), iVar11 == 0)) {
          cVar10 = *(char *)(iVar7 + 0x17) + -1;
        }
        else {
          cVar10 = *(char *)(iVar7 + 0x17);
        }
        uStack_36 = CONCAT11(uStack_36._1_1_,cVar10);
        (**(code **)(_bt_rf_coex_hooks_p + 4))
                  (uVar13,4,&uStack_3c,*(code **)(_bt_rf_coex_hooks_p + 4));
      }
    }
    uVar8 = 0;
  }
_L447:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar8,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

