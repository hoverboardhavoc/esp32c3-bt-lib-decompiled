/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app -> llm_adv.o -> hci_le_set_ext_scan_rsp_data_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_ext_scan_rsp_data_cmd_handler(undefined1 *param_1,undefined4 param_2)

{
  byte bVar1;
  undefined2 uVar2;
  bool bVar3;
  int iVar4;
  ushort uVar5;
  undefined2 uVar6;
  int iVar7;
  void *__dest;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  code *pcVar12;
  int iStack_30;
  uint uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined1 uStack_24;
  char cStack_23;
  char cStack_22;
  undefined1 uStack_21;
  
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  iVar7 = _r_ip_funcs_p;
  if (*(char *)(iVar8 + 0x18) == '\0') {
    (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,0xc,*(code **)(_r_ip_funcs_p + 0x4b8));
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L283:
    uVar9 = 0xc;
    goto _L310;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  iVar7 = (**(code **)(iVar7 + 0x544))(*param_1,&iStack_30,*(code **)(iVar7 + 0x544));
  uVar9 = 0x42;
  if (iVar7 == 0xff) goto _L310;
  bVar1 = param_1[1];
  uVar9 = 0x12;
  if (((3 < bVar1) || (1 < (byte)param_1[2])) || (uVar10 = (uint)(byte)param_1[3], 0xfb < uVar10))
  goto _L310;
  uVar5 = *(ushort *)(iStack_30 + 2);
  if ((uVar5 & 0x10) == 0) {
    if ((bVar1 != 3) && (uVar10 == 0)) goto _L310;
  }
  else if ((bVar1 != 3) || (0x1f < uVar10)) goto _L310;
  if (((uVar5 & 2) == 0) && (uVar9 = 0x12, uVar10 != 0)) goto _L310;
  iVar8 = iVar7 * 0x44;
  iVar11 = *(int *)(_p_llm_env + 8) + iVar8;
  if (*(char *)(iVar11 + 0x40) != '\x01') {
    if ((bVar1 != 3) || ((((uVar5 & 2) != 0 && (uVar10 == 0)) && ((uVar5 & 0x10) == 0))))
    goto _L283;
    uVar9 = 0x12;
    if (((uVar5 & 0x12) == 0x12) && (0x1f < uVar10)) goto _L310;
  }
  if ((uint)*(ushort *)(iVar11 + 0x3a) < uVar10 + *(ushort *)(iVar11 + 0x38)) {
    if (*(short *)(iVar11 + 0x36) != 0) {
      (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
      iVar8 = *(int *)(_p_llm_env + 8) + iVar8;
      *(undefined2 *)(iVar8 + 0x36) = 0;
      *(undefined2 *)(iVar8 + 0x38) = 0;
    }
_L345:
    uVar9 = 7;
  }
  else {
    if ((bVar1 & 0xfd) == 1) {
      if (*(short *)(iVar11 + 0x36) != 0) {
        (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
        *(undefined2 *)(*(int *)(_p_llm_env + 8) + iVar8 + 0x38) = 0;
      }
      iVar11 = *(int *)(_p_llm_env + 8) + iVar8;
      if (param_1[1] == '\x03') {
        uVar5 = (ushort)(byte)param_1[3];
        if (uVar5 != 0) {
          pcVar12 = *(code **)(_r_ip_funcs_p + 0xd4);
          goto _L344;
        }
        uVar6 = 0;
        bVar3 = true;
      }
      else {
        uVar5 = *(ushort *)(iVar11 + 0x3a);
        pcVar12 = *(code **)(_r_ip_funcs_p + 0xd4);
_L344:
        uVar6 = (*pcVar12)(uVar5,pcVar12);
        bVar3 = false;
      }
      iVar4 = _p_llm_env;
      *(undefined2 *)(iVar11 + 0x36) = uVar6;
      if ((*(short *)(*(int *)(iVar4 + 8) + iVar8 + 0x36) == 0) && (!bVar3)) goto _L345;
    }
    bVar1 = param_1[3];
    if (bVar1 != 0) {
      iVar11 = *(int *)(_p_llm_env + 8) + iVar8;
      __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                 (*(short *)(iVar11 + 0x36) + *(short *)(iVar11 + 0x38),
                                  *(code **)(_r_plf_funcs_p + 0xbc));
      memcpy(__dest,param_1 + 4,(uint)bVar1);
      iVar11 = *(int *)(_p_llm_env + 8) + iVar8;
      *(ushort *)(iVar11 + 0x38) = *(short *)(iVar11 + 0x38) + (ushort)(byte)param_1[3];
    }
    if ((byte)(param_1[1] - 2) < 2) {
      iVar11 = *(int *)(_p_llm_env + 8) + iVar8;
      if (*(char *)(iVar11 + 0x40) == '\x02') {
        (**(code **)(_r_ip_funcs_p + 0x1dc))
                  (iVar7,*(undefined1 *)(iVar11 + 0x38),*(undefined2 *)(iVar11 + 0x36),
                   *(code **)(_r_ip_funcs_p + 0x1dc));
      }
      else if (*(short *)(iVar11 + 0x32) != 0) {
        (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
      }
      iVar8 = *(int *)(_p_llm_env + 8) + iVar8;
      uVar6 = *(undefined2 *)(iVar8 + 0x36);
      uVar2 = *(undefined2 *)(iVar8 + 0x38);
      *(undefined2 *)(iVar8 + 0x36) = 0;
      *(undefined2 *)(iVar8 + 0x32) = uVar6;
      iVar11 = _bt_rf_coex_hooks_p;
      *(undefined2 *)(iVar8 + 0x34) = uVar2;
      *(undefined2 *)(iVar8 + 0x38) = 0;
      if ((iVar11 != 0) && (*(int *)(iVar11 + 4) != 0)) {
        uStack_28 = *(undefined2 *)(iVar8 + 0x2a);
        uStack_24 = *(undefined1 *)(iStack_30 + 10);
        uStack_2c = (uint)*(byte *)(iStack_30 + 9) << 0x10 | (uint)*(byte *)(iStack_30 + 8) << 8 |
                    (uint)*(byte *)(iStack_30 + 7);
        uStack_26 = uVar2;
        if ((*(byte *)(iStack_30 + 0x15) < 3) || (iVar8 = lld_phy_coded_500k_get(), iVar8 == 0)) {
          cStack_23 = *(char *)(iStack_30 + 0x15) + -1;
        }
        else {
          cStack_23 = *(char *)(iStack_30 + 0x15);
        }
        if ((*(byte *)(iStack_30 + 0x17) < 3) || (iVar8 = lld_phy_coded_500k_get(), iVar8 == 0)) {
          cStack_22 = *(char *)(iStack_30 + 0x17) + -1;
        }
        else {
          cStack_22 = *(char *)(iStack_30 + 0x17);
        }
        uStack_21 = *(undefined1 *)(iStack_30 + 0x16);
        (**(code **)(_bt_rf_coex_hooks_p + 4))
                  (iVar7,2,&uStack_2c,*(code **)(_bt_rf_coex_hooks_p + 4));
      }
    }
    else if (param_1[1] == '\x04') {
      (**(code **)(_r_ip_funcs_p + 0x1dc))(iVar7,0,0,*(code **)(_r_ip_funcs_p + 0x1dc));
    }
    uVar9 = 0;
  }
_L310:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar9,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

