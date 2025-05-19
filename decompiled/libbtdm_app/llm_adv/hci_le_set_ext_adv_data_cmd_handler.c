/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
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
  int iVar4;
  ushort uVar5;
  undefined2 uVar6;
  int iVar7;
  int iVar8;
  void *__dest;
  int iVar9;
  undefined4 uVar10;
  code *pcVar11;
  int iStack_30;
  uint uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined1 uStack_24;
  char cStack_23;
  char cStack_22;
  undefined1 uStack_21;
  
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  iVar7 = _r_ip_funcs_p;
  if (*(char *)(iVar9 + 0x18) == '\0') {
    (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,0xc,*(code **)(_r_ip_funcs_p + 0x4b8));
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
    uVar10 = 0xc;
    goto _L245;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  iVar7 = (**(code **)(iVar7 + 0x544))(*param_1,&iStack_30,*(code **)(iVar7 + 0x544));
  uVar10 = 0x42;
  if (iVar7 == 0xff) goto _L245;
  bVar1 = param_1[1];
  if (((bVar1 < 5) && ((byte)param_1[2] < 2)) && (bVar2 = param_1[3], bVar2 < 0xfc)) {
    uVar5 = *(ushort *)(iStack_30 + 2);
    if ((uVar5 & 0x10) == 0) {
      if ((bVar1 != 4) ||
         (((iVar9 = *(int *)(_p_llm_env + 8) + iVar7 * 0x44, *(char *)(iVar9 + 0x40) != '\x01' &&
           (*(short *)(iVar9 + 0x28) != 0)) && (bVar2 == 0)))) goto _L215;
    }
    else if ((bVar1 == 3) && (bVar2 < 0x20)) {
_L215:
      if ((((byte)(bVar1 - 3) < 2) || (bVar2 != 0)) && ((uVar5 & 0x12) != 2)) {
        iVar9 = iVar7 * 0x44;
        if (*(char *)(*(int *)(_p_llm_env + 8) + iVar9 + 0x40) != '\x01') {
          uVar10 = 0xc;
          if (1 < (byte)(bVar1 - 3)) goto _L245;
          if ((((uVar5 & 0x11) == 1) &&
              (iVar8 = (**(code **)(_r_ip_funcs_p + 0x540))(*(code **)(_r_ip_funcs_p + 0x540)),
              iVar8 != 0)) ||
             (((*(ushort *)(iStack_30 + 2) & 0x1c) == 0x10 && (0x1f < (byte)param_1[3]))))
          goto _L213;
        }
        if ((*(ushort *)(iStack_30 + 2) & 0x11) == 1) {
          iVar8 = (**(code **)(_r_ip_funcs_p + 0x540))(param_1[3],*(code **)(_r_ip_funcs_p + 0x540))
          ;
          uVar10 = 0x45;
          if (iVar8 != 0) goto _L245;
        }
        iVar8 = *(int *)(_p_llm_env + 8) + iVar9;
        if ((uint)*(ushort *)(iVar8 + 0x30) <
            (uint)*(ushort *)(iVar8 + 0x2e) + (uint)(byte)param_1[3]) {
          if (*(short *)(iVar8 + 0x2c) != 0) {
            (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
            *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar9 + 0x2c) = 0;
          }
_L275:
          uVar10 = 7;
        }
        else {
          if ((param_1[1] & 0xfd) == 1) {
            if (*(short *)(iVar8 + 0x2c) != 0) {
              (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
              *(undefined2 *)(*(int *)(_p_llm_env + 8) + iVar9 + 0x2e) = 0;
            }
            iVar8 = *(int *)(_p_llm_env + 8) + iVar9;
            if (param_1[1] == '\x03') {
              uVar5 = (ushort)(byte)param_1[3];
              if (uVar5 != 0) {
                pcVar11 = *(code **)(_r_ip_funcs_p + 0xd4);
                goto _L274;
              }
              uVar6 = 0;
              bVar3 = true;
            }
            else {
              uVar5 = *(ushort *)(iVar8 + 0x30);
              pcVar11 = *(code **)(_r_ip_funcs_p + 0xd4);
_L274:
              uVar6 = (*pcVar11)(uVar5,pcVar11);
              bVar3 = false;
            }
            iVar4 = _p_llm_env;
            *(undefined2 *)(iVar8 + 0x2c) = uVar6;
            if ((*(short *)(*(int *)(iVar4 + 8) + iVar9 + 0x2c) == 0) && (!bVar3)) goto _L275;
          }
          bVar1 = param_1[3];
          if (bVar1 != 0) {
            iVar8 = *(int *)(_p_llm_env + 8) + iVar9;
            __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                       (*(short *)(iVar8 + 0x2c) + *(short *)(iVar8 + 0x2e),
                                        *(code **)(_r_plf_funcs_p + 0xbc));
            memcpy(__dest,param_1 + 4,(uint)bVar1);
            iVar8 = *(int *)(_p_llm_env + 8) + iVar9;
            *(ushort *)(iVar8 + 0x2e) = *(short *)(iVar8 + 0x2e) + (ushort)(byte)param_1[3];
          }
          if ((byte)(param_1[1] - 2) < 2) {
            iVar8 = *(int *)(_p_llm_env + 8) + iVar9;
            if (*(char *)(iVar8 + 0x40) == '\x02') {
              (**(code **)(_r_ip_funcs_p + 0x180))
                        (iVar7,*(undefined1 *)(iVar8 + 0x2e),*(undefined2 *)(iVar8 + 0x2c),
                         *(code **)(_r_ip_funcs_p + 0x180));
            }
            else if (*(short *)(iVar8 + 0x28) != 0) {
              (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
            }
            iVar9 = *(int *)(_p_llm_env + 8) + iVar9;
            uVar10 = *(undefined4 *)(iVar9 + 0x2c);
            *(undefined4 *)(iVar9 + 0x2c) = 0;
            *(undefined4 *)(iVar9 + 0x28) = uVar10;
            if ((_bt_rf_coex_hooks_p != 0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
              uStack_26 = *(undefined2 *)(iVar9 + 0x34);
              uStack_24 = *(undefined1 *)(iStack_30 + 10);
              uStack_2c = (uint)*(byte *)(iStack_30 + 9) << 0x10 |
                          (uint)*(byte *)(iStack_30 + 8) << 8 | (uint)*(byte *)(iStack_30 + 7);
              uStack_28 = *(undefined2 *)(iVar9 + 0x2e);
              if ((*(byte *)(iStack_30 + 0x15) < 3) ||
                 (iVar9 = lld_phy_coded_500k_get(), iVar9 == 0)) {
                cStack_23 = *(char *)(iStack_30 + 0x15) + -1;
              }
              else {
                cStack_23 = *(char *)(iStack_30 + 0x15);
              }
              if ((*(byte *)(iStack_30 + 0x17) < 3) ||
                 (iVar9 = lld_phy_coded_500k_get(), iVar9 == 0)) {
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
            (**(code **)(_r_ip_funcs_p + 0x180))(iVar7,0,0,*(code **)(_r_ip_funcs_p + 0x180));
          }
          uVar10 = 0;
        }
        goto _L245;
      }
    }
  }
_L213:
  uVar10 = 0x12;
_L245:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar10,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

