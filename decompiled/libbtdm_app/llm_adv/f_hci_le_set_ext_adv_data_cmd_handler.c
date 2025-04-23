/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_adv.o -> f_hci_le_set_ext_adv_data_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_ext_adv_data_cmd_handler(undefined1 *param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  ushort uVar4;
  undefined2 uVar5;
  int iVar6;
  void *__dest;
  undefined4 uVar7;
  uint uVar8;
  uint extraout_a1;
  byte bVar9;
  code *pcVar10;
  int iVar11;
  int iStack_30;
  uint uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined1 uStack_24;
  char cStack_23;
  char cStack_22;
  undefined1 uStack_21;
  
  iVar6 = _r_ip_funcs_p;
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L188:
    uVar7 = 0xc;
    goto _L226;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  iVar6 = (**(code **)(iVar6 + 0x544))(*param_1,&iStack_30,*(code **)(iVar6 + 0x544));
  uVar7 = 0x42;
  if (iVar6 == 0xff) goto _L226;
  bVar9 = param_1[1];
  if (((bVar9 < 5) && ((byte)param_1[2] < 2)) && (uVar8 = (uint)(byte)param_1[3], uVar8 < 0xfc)) {
    uVar4 = *(ushort *)(iStack_30 + 2);
    if ((uVar4 & 0x10) == 0) {
      if (bVar9 == 4) {
        iVar11 = *(int *)(_p_llm_env + 8) + iVar6 * 0x44;
        if (((*(char *)(iVar11 + 0x40) != '\x01') && (*(short *)(iVar11 + 0x28) != 0)) &&
           (bVar9 = 1, uVar8 == 0)) goto _L193;
      }
      else {
        bVar9 = bVar9 - 3;
        if (bVar9 < 2) goto _L228;
        if (uVar8 != 0) goto _L193;
      }
    }
    else if ((bVar9 == 3) && (uVar8 < 0x20)) {
_L228:
      bVar9 = 0;
_L193:
      if ((uVar4 & 0x12) != 2) {
        iVar11 = iVar6 * 0x44;
        if (*(char *)(*(int *)(_p_llm_env + 8) + iVar11 + 0x40) != '\x01') {
          if (1 < bVar9) goto _L188;
          if ((((uVar4 & 0x11) == 1) &&
              (iVar3 = (**(code **)(_r_ip_funcs_p + 0x540))(*(code **)(_r_ip_funcs_p + 0x540)),
              uVar8 = extraout_a1, iVar3 != 0)) ||
             ((uVar4 = *(ushort *)(iStack_30 + 2), (uVar4 & 0x1c) == 0x10 &&
              (0x1f < (byte)param_1[3])))) goto _L191;
        }
        if ((uVar4 & 0x11) == 1) {
          iVar3 = (**(code **)(_r_ip_funcs_p + 0x540))(param_1[3],*(code **)(_r_ip_funcs_p + 0x540))
          ;
          uVar8 = 0x45;
          uVar7 = 0x45;
          if (iVar3 != 0) goto _L226;
        }
        iVar3 = *(int *)(_p_llm_env + 8) + iVar11;
        if ((uint)*(ushort *)(iVar3 + 0x30) <
            (uint)*(ushort *)(iVar3 + 0x2e) + (uint)(byte)param_1[3]) {
          if (*(short *)(iVar3 + 0x2c) != 0) {
            (**(code **)(_r_ip_funcs_p + 0xd8))(uVar8,*(code **)(_r_ip_funcs_p + 0xd8));
            *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar11 + 0x2c) = 0;
          }
_L205:
          uVar7 = 7;
        }
        else {
          if ((param_1[1] & 0xfd) == 1) {
            if (*(short *)(iVar3 + 0x2c) != 0) {
              (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
              iVar3 = *(int *)(_p_llm_env + 8) + iVar11;
              *(undefined2 *)(iVar3 + 0x2e) = 0;
            }
            if (param_1[1] == '\x03') {
              uVar4 = (ushort)(byte)param_1[3];
              if (uVar4 != 0) {
                pcVar10 = *(code **)(_r_ip_funcs_p + 0xd4);
                goto _L254;
              }
              uVar5 = 0;
              bVar1 = true;
            }
            else {
              uVar4 = *(ushort *)(iVar3 + 0x30);
              pcVar10 = *(code **)(_r_ip_funcs_p + 0xd4);
_L254:
              uVar5 = (*pcVar10)(uVar4,pcVar10);
              bVar1 = false;
            }
            iVar2 = _p_llm_env;
            *(undefined2 *)(iVar3 + 0x2c) = uVar5;
            if ((*(short *)(*(int *)(iVar2 + 8) + iVar11 + 0x2c) == 0) && (!bVar1)) goto _L205;
          }
          bVar9 = param_1[3];
          if (bVar9 != 0) {
            iVar3 = *(int *)(_p_llm_env + 8) + iVar11;
            __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                       (*(short *)(iVar3 + 0x2c) + *(short *)(iVar3 + 0x2e),
                                        *(code **)(_r_plf_funcs_p + 0xbc));
            memcpy(__dest,param_1 + 4,(uint)bVar9);
            iVar3 = *(int *)(_p_llm_env + 8) + iVar11;
            *(ushort *)(iVar3 + 0x2e) = *(short *)(iVar3 + 0x2e) + (ushort)(byte)param_1[3];
          }
          if ((byte)(param_1[1] - 2) < 2) {
            iVar3 = *(int *)(_p_llm_env + 8) + iVar11;
            if (*(char *)(iVar3 + 0x40) == '\x02') {
              (**(code **)(_r_ip_funcs_p + 0x180))
                        (iVar6,*(undefined1 *)(iVar3 + 0x2e),*(undefined2 *)(iVar3 + 0x2c),
                         *(code **)(_r_ip_funcs_p + 0x180));
            }
            else if (*(short *)(iVar3 + 0x28) != 0) {
              (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
            }
            iVar11 = *(int *)(_p_llm_env + 8) + iVar11;
            uVar7 = *(undefined4 *)(iVar11 + 0x2c);
            *(undefined4 *)(iVar11 + 0x2c) = 0;
            *(undefined4 *)(iVar11 + 0x28) = uVar7;
            if ((_bt_rf_coex_hooks_p != 0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
              uStack_26 = *(undefined2 *)(iVar11 + 0x34);
              uStack_24 = *(undefined1 *)(iStack_30 + 10);
              uStack_2c = (uint)*(byte *)(iStack_30 + 9) << 0x10 |
                          (uint)*(byte *)(iStack_30 + 8) << 8 | (uint)*(byte *)(iStack_30 + 7);
              uStack_28 = *(undefined2 *)(iVar11 + 0x2e);
              if ((*(byte *)(iStack_30 + 0x15) < 3) ||
                 (iVar11 = lld_phy_coded_500k_get(), iVar11 == 0)) {
                cStack_23 = *(char *)(iStack_30 + 0x15) + -1;
              }
              else {
                cStack_23 = *(char *)(iStack_30 + 0x15);
              }
              if ((*(byte *)(iStack_30 + 0x17) < 3) ||
                 (iVar11 = lld_phy_coded_500k_get(), iVar11 == 0)) {
                cStack_22 = *(char *)(iStack_30 + 0x17) + -1;
              }
              else {
                cStack_22 = *(char *)(iStack_30 + 0x17);
              }
              uStack_21 = *(undefined1 *)(iStack_30 + 0x16);
              (**(code **)(_bt_rf_coex_hooks_p + 4))
                        (iVar6,2,&uStack_2c,*(code **)(_bt_rf_coex_hooks_p + 4));
            }
          }
          else if (param_1[1] == '\x04') {
            (**(code **)(_r_ip_funcs_p + 0x180))(iVar6,0,0,*(code **)(_r_ip_funcs_p + 0x180));
          }
          uVar7 = 0;
        }
        goto _L226;
      }
    }
  }
_L191:
  uVar7 = 0x12;
_L226:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar7,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

