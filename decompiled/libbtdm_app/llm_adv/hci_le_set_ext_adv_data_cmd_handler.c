/*
 * Last changed at upstream commit 0cfac1b21ebc995e8e9aa040ab1ab29deee4f580
 * https://github.com/espressif/esp32c3-bt-lib/commit/0cfac1b21ebc995e8e9aa040ab1ab29deee4f580
 * Upstream date: 2023-08-10 21:56:13 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(59725b5)
 * Source: libbtdm_app -> llm_adv.o -> hci_le_set_ext_adv_data_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_ext_adv_data_cmd_handler(undefined1 *param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  ushort uVar4;
  undefined2 uVar5;
  int iVar6;
  void *__dest;
  undefined4 uVar7;
  int iVar8;
  code *pcVar9;
  int iVar10;
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
    uVar7 = 0xc;
    goto _L205;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  iVar6 = (**(code **)(iVar6 + 0x544))(*param_1,&iStack_30,*(code **)(iVar6 + 0x544));
  uVar7 = 0x42;
  if (iVar6 == 0xff) goto _L205;
  bVar1 = param_1[1];
  if (((bVar1 < 5) && ((byte)param_1[2] < 2)) && (bVar2 = param_1[3], bVar2 < 0xfc)) {
    uVar4 = *(ushort *)(iStack_30 + 2);
    if ((uVar4 & 0x10) == 0) {
      if ((bVar1 != 4) ||
         (((iVar10 = *(int *)(_p_llm_env + 8) + iVar6 * 0x44, *(char *)(iVar10 + 0x40) != '\x01' &&
           (*(short *)(iVar10 + 0x28) != 0)) && (bVar2 == 0)))) goto _L176;
    }
    else if ((bVar1 == 3) && (bVar2 < 0x20)) {
_L176:
      if ((((byte)(bVar1 - 3) < 2) || (bVar2 != 0)) && ((uVar4 & 0x12) != 2)) {
        iVar10 = iVar6 * 0x44;
        if (*(char *)(*(int *)(_p_llm_env + 8) + iVar10 + 0x40) != '\x01') {
          uVar7 = 0xc;
          if (1 < (byte)(bVar1 - 3)) goto _L205;
          if ((((uVar4 & 0x11) == 1) &&
              (iVar8 = (**(code **)(_r_ip_funcs_p + 0x540))(*(code **)(_r_ip_funcs_p + 0x540)),
              iVar8 != 0)) ||
             (((*(ushort *)(iStack_30 + 2) & 0x1c) == 0x10 && (0x1f < (byte)param_1[3]))))
          goto _L174;
        }
        iVar8 = *(int *)(_p_llm_env + 8) + iVar10;
        if ((uint)*(ushort *)(iVar8 + 0x30) <
            (uint)*(ushort *)(iVar8 + 0x2e) + (uint)(byte)param_1[3]) {
          if (*(short *)(iVar8 + 0x2c) != 0) {
            (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
            *(undefined4 *)(iVar10 + *(int *)(_p_llm_env + 8) + 0x2c) = 0;
          }
_L233:
          uVar7 = 7;
        }
        else {
          if ((param_1[1] & 0xfd) == 1) {
            if (*(short *)(iVar8 + 0x2c) != 0) {
              (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
              *(undefined2 *)(*(int *)(_p_llm_env + 8) + iVar10 + 0x2e) = 0;
            }
            iVar8 = *(int *)(_p_llm_env + 8) + iVar10;
            if (param_1[1] == '\x03') {
              uVar4 = (ushort)(byte)param_1[3];
              if (uVar4 != 0) {
                pcVar9 = *(code **)(_r_ip_funcs_p + 0xd4);
                goto _L232;
              }
              *(undefined2 *)(iVar8 + 0x2c) = 0;
              bVar3 = true;
            }
            else {
              uVar4 = *(ushort *)(iVar8 + 0x30);
              pcVar9 = *(code **)(_r_ip_funcs_p + 0xd4);
_L232:
              uVar5 = (*pcVar9)(uVar4,pcVar9);
              *(undefined2 *)(iVar8 + 0x2c) = uVar5;
              bVar3 = false;
            }
            if ((*(short *)(*(int *)(_p_llm_env + 8) + iVar10 + 0x2c) == 0) && (!bVar3)) goto _L233;
          }
          bVar1 = param_1[3];
          if (bVar1 != 0) {
            iVar8 = *(int *)(_p_llm_env + 8) + iVar10;
            __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                       (*(short *)(iVar8 + 0x2c) + *(short *)(iVar8 + 0x2e),
                                        *(code **)(_r_plf_funcs_p + 0xbc));
            memcpy(__dest,param_1 + 4,(uint)bVar1);
            iVar8 = *(int *)(_p_llm_env + 8) + iVar10;
            *(ushort *)(iVar8 + 0x2e) = *(short *)(iVar8 + 0x2e) + (ushort)(byte)param_1[3];
          }
          if ((byte)(param_1[1] - 2) < 2) {
            iVar8 = *(int *)(_p_llm_env + 8) + iVar10;
            if (*(char *)(iVar8 + 0x40) == '\x02') {
              (**(code **)(_r_ip_funcs_p + 0x180))
                        (iVar6,*(undefined1 *)(iVar8 + 0x2e),*(undefined2 *)(iVar8 + 0x2c),
                         *(code **)(_r_ip_funcs_p + 0x180));
            }
            else if (*(short *)(iVar8 + 0x28) != 0) {
              (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
            }
            iVar10 = iVar10 + *(int *)(_p_llm_env + 8);
            uVar7 = *(undefined4 *)(iVar10 + 0x2c);
            *(undefined4 *)(iVar10 + 0x2c) = 0;
            *(undefined4 *)(iVar10 + 0x28) = uVar7;
            if ((_bt_rf_coex_hooks_p != 0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
              uStack_2c = (uint)*(byte *)(iStack_30 + 9) << 0x10 |
                          (uint)*(byte *)(iStack_30 + 8) << 8 | (uint)*(byte *)(iStack_30 + 7);
              uStack_26 = *(undefined2 *)(iVar10 + 0x34);
              uStack_24 = *(undefined1 *)(iStack_30 + 10);
              uStack_28 = *(undefined2 *)(iVar10 + 0x2e);
              if ((*(byte *)(iStack_30 + 0x15) < 3) ||
                 (iVar10 = lld_phy_coded_500k_get(), iVar10 == 0)) {
                cStack_23 = *(char *)(iStack_30 + 0x15) + -1;
              }
              else {
                cStack_23 = *(char *)(iStack_30 + 0x15);
              }
              if ((*(byte *)(iStack_30 + 0x17) < 3) ||
                 (iVar10 = lld_phy_coded_500k_get(), iVar10 == 0)) {
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
        goto _L205;
      }
    }
  }
_L174:
  uVar7 = 0x12;
_L205:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar7,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

