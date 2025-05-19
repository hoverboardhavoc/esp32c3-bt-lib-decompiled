/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app -> llm_adv.o -> f_hci_le_set_ext_adv_data_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_ext_adv_data_cmd_handler(undefined1 *param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  undefined2 uVar7;
  int iVar8;
  int iVar9;
  void *__dest;
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
  
  iVar8 = _r_ip_funcs_p;
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
    uVar10 = 0xc;
    goto _L245;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  iVar8 = (**(code **)(iVar8 + 0x544))(*param_1,&iStack_30,*(code **)(iVar8 + 0x544));
  uVar10 = 0x42;
  if (iVar8 == 0xff) goto _L245;
  bVar1 = param_1[1];
  if (((bVar1 < 5) && ((byte)param_1[2] < 2)) && (bVar2 = param_1[3], bVar2 < 0xfc)) {
    uVar6 = *(ushort *)(iStack_30 + 2);
    if ((uVar6 & 0x10) == 0) {
      if ((bVar1 != 4) ||
         (((iVar5 = *(int *)(_p_llm_env + 8) + iVar8 * 0x44, *(char *)(iVar5 + 0x40) != '\x01' &&
           (*(short *)(iVar5 + 0x28) != 0)) && (bVar2 == 0)))) goto _L215;
    }
    else if ((bVar1 == 3) && (bVar2 < 0x20)) {
_L215:
      if ((((byte)(bVar1 - 3) < 2) || (bVar2 != 0)) && ((uVar6 & 0x12) != 2)) {
        iVar5 = iVar8 * 0x44;
        if (*(char *)(*(int *)(_p_llm_env + 8) + iVar5 + 0x40) != '\x01') {
          uVar10 = 0xc;
          if (1 < (byte)(bVar1 - 3)) goto _L245;
          if ((((uVar6 & 0x11) == 1) &&
              (iVar9 = (**(code **)(_r_ip_funcs_p + 0x540))(*(code **)(_r_ip_funcs_p + 0x540)),
              iVar9 != 0)) ||
             (((*(ushort *)(iStack_30 + 2) & 0x1c) == 0x10 && (0x1f < (byte)param_1[3]))))
          goto _L213;
        }
        if ((*(ushort *)(iStack_30 + 2) & 0x11) == 1) {
          iVar9 = (**(code **)(_r_ip_funcs_p + 0x540))(param_1[3],*(code **)(_r_ip_funcs_p + 0x540))
          ;
          uVar10 = 0x45;
          if (iVar9 != 0) goto _L245;
        }
        iVar9 = *(int *)(_p_llm_env + 8) + iVar5;
        if ((uint)*(ushort *)(iVar9 + 0x30) <
            (uint)*(ushort *)(iVar9 + 0x2e) + (uint)(byte)param_1[3]) {
          if (*(short *)(iVar9 + 0x2c) != 0) {
            (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
            *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar5 + 0x2c) = 0;
          }
_L275:
          uVar10 = 7;
        }
        else {
          if ((param_1[1] & 0xfd) == 1) {
            if (*(short *)(iVar9 + 0x2c) != 0) {
              (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
              *(undefined2 *)(*(int *)(_p_llm_env + 8) + iVar5 + 0x2e) = 0;
            }
            iVar9 = *(int *)(_p_llm_env + 8) + iVar5;
            if (param_1[1] == '\x03') {
              uVar6 = (ushort)(byte)param_1[3];
              if (uVar6 != 0) {
                pcVar11 = *(code **)(_r_ip_funcs_p + 0xd4);
                goto _L274;
              }
              uVar7 = 0;
              bVar3 = true;
            }
            else {
              uVar6 = *(ushort *)(iVar9 + 0x30);
              pcVar11 = *(code **)(_r_ip_funcs_p + 0xd4);
_L274:
              uVar7 = (*pcVar11)(uVar6,pcVar11);
              bVar3 = false;
            }
            iVar4 = _p_llm_env;
            *(undefined2 *)(iVar9 + 0x2c) = uVar7;
            if ((*(short *)(*(int *)(iVar4 + 8) + iVar5 + 0x2c) == 0) && (!bVar3)) goto _L275;
          }
          bVar1 = param_1[3];
          if (bVar1 != 0) {
            iVar9 = *(int *)(_p_llm_env + 8) + iVar5;
            __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                       (*(short *)(iVar9 + 0x2c) + *(short *)(iVar9 + 0x2e),
                                        *(code **)(_r_plf_funcs_p + 0xbc));
            memcpy(__dest,param_1 + 4,(uint)bVar1);
            iVar9 = *(int *)(_p_llm_env + 8) + iVar5;
            *(ushort *)(iVar9 + 0x2e) = *(short *)(iVar9 + 0x2e) + (ushort)(byte)param_1[3];
          }
          if ((byte)(param_1[1] - 2) < 2) {
            iVar9 = *(int *)(_p_llm_env + 8) + iVar5;
            if (*(char *)(iVar9 + 0x40) == '\x02') {
              (**(code **)(_r_ip_funcs_p + 0x180))
                        (iVar8,*(undefined1 *)(iVar9 + 0x2e),*(undefined2 *)(iVar9 + 0x2c),
                         *(code **)(_r_ip_funcs_p + 0x180));
            }
            else if (*(short *)(iVar9 + 0x28) != 0) {
              (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
            }
            iVar5 = *(int *)(_p_llm_env + 8) + iVar5;
            uVar10 = *(undefined4 *)(iVar5 + 0x2c);
            *(undefined4 *)(iVar5 + 0x2c) = 0;
            *(undefined4 *)(iVar5 + 0x28) = uVar10;
            if ((_bt_rf_coex_hooks_p != 0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
              uStack_26 = *(undefined2 *)(iVar5 + 0x34);
              uStack_24 = *(undefined1 *)(iStack_30 + 10);
              uStack_2c = (uint)*(byte *)(iStack_30 + 9) << 0x10 |
                          (uint)*(byte *)(iStack_30 + 8) << 8 | (uint)*(byte *)(iStack_30 + 7);
              uStack_28 = *(undefined2 *)(iVar5 + 0x2e);
              if ((*(byte *)(iStack_30 + 0x15) < 3) ||
                 (iVar5 = lld_phy_coded_500k_get(), iVar5 == 0)) {
                cStack_23 = *(char *)(iStack_30 + 0x15) + -1;
              }
              else {
                cStack_23 = *(char *)(iStack_30 + 0x15);
              }
              if ((*(byte *)(iStack_30 + 0x17) < 3) ||
                 (iVar5 = lld_phy_coded_500k_get(), iVar5 == 0)) {
                cStack_22 = *(char *)(iStack_30 + 0x17) + -1;
              }
              else {
                cStack_22 = *(char *)(iStack_30 + 0x17);
              }
              uStack_21 = *(undefined1 *)(iStack_30 + 0x16);
              (**(code **)(_bt_rf_coex_hooks_p + 4))
                        (iVar8,2,&uStack_2c,*(code **)(_bt_rf_coex_hooks_p + 4));
            }
          }
          else if (param_1[1] == '\x04') {
            (**(code **)(_r_ip_funcs_p + 0x180))(iVar8,0,0,*(code **)(_r_ip_funcs_p + 0x180));
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

