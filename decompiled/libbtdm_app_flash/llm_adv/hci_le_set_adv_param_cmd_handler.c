/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm_adv.o -> hci_le_set_adv_param_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_adv_param_cmd_handler(ushort *param_1,undefined4 param_2)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  undefined1 uVar6;
  uint uVar7;
  int *piVar8;
  char cVar9;
  byte bStack_3d;
  uint uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  
  if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
    iVar5 = r_sdk_config_get_opts_ext();
    cVar9 = *(char *)(iVar5 + 0x25);
    if (cVar9 != '\0') {
      *(undefined1 *)(_p_llm_env + 0xd7) = 1;
      iVar5 = r_llm_adv_hdl_to_id(0xff,0);
      bStack_3d = (byte)iVar5;
      if (iVar5 == 0xff) {
        uVar7 = r_llm_activity_free_get(&bStack_3d);
        if (uVar7 != 0) {
          r_ble_log_internal_x1(0x802e014d,(uint)bStack_3d << 8 | uVar7);
          goto _L253;
        }
        r_llm_adv_set_dft_params();
      }
      else {
        uVar7 = (uint)*(byte *)(*(int *)(_p_llm_env + 8) + iVar5 * 0x44 + 0x40);
        if (uVar7 != 1) {
          r_ble_log_internal_x1(0x802e014c,uVar7 << 0x10 | iVar5 << 8 | 0xc);
          goto _L235;
        }
      }
      *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44 + 0x3d) = 0xff;
      if ((byte)param_1[2] < 5) {
        if ((byte)param_1[2] != 1) {
          if (((param_1[1] < *param_1) || (*param_1 < 8)) || (0x4000 < param_1[1])) goto _L273;
        }
        if ((((byte)(*(char *)((int)param_1 + 0xd) - 1U) < 7) && ((byte)param_1[7] < 4)) &&
           ((*(byte *)((int)param_1 + 5) < 4 && ((byte)param_1[3] < 2)))) {
          iVar5 = r_sdk_config_get_opts_ext();
          cVar1 = (char)param_1[2];
          if ((*(char *)(iVar5 + 0x22) != '\0') || ((byte)(cVar1 - 2U) < 2)) {
            if ((cVar1 == '\x01') || (cVar1 == '\x04')) {
              iVar5 = r_co_bdaddr_compare((void *)((int)param_1 + 7),&co_null_bdaddr);
              if (iVar5 != 0) {
                r_ble_log_internal_x1
                          (0x802e014e,(uint)bStack_3d << 8 | (uint)(byte)param_1[2] << 0x10 | 0x12);
                goto _L273;
              }
            }
            else {
              cVar9 = '\0';
            }
            iVar5 = _p_llm_env;
            piVar8 = (int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44);
            iVar4 = *piVar8;
            *(ushort *)(iVar4 + 2) = (ushort)(byte)(&adv_evt_type2prop)[(byte)param_1[2]];
            uVar3 = param_1[1];
            *(undefined1 *)(iVar4 + 9) = 0;
            *(char *)(iVar4 + 8) = (char)(uVar3 >> 8);
            *(char *)(iVar4 + 7) = (char)uVar3;
            uVar3 = *param_1;
            *(undefined1 *)(iVar4 + 6) = 0;
            *(ushort *)(iVar4 + 4) = uVar3;
            *(undefined1 *)(iVar4 + 10) = *(undefined1 *)((int)param_1 + 0xd);
            bVar2 = *(byte *)((int)param_1 + 5);
            *(byte *)(iVar4 + 0xb) = bVar2;
            *(char *)(iVar4 + 0xc) = (char)param_1[3];
            memcpy((void *)(iVar4 + 0xd),(void *)((int)param_1 + 7),6);
            uVar6 = 0;
            if (cVar9 == '\0') {
              uVar6 = (undefined1)param_1[7];
            }
            *(undefined1 *)(iVar4 + 0x13) = uVar6;
            if (bVar2 == 2) {
_L247:
              piVar8[1] = *(int *)(iVar5 + 0xc);
              *(undefined2 *)(piVar8 + 2) = *(undefined2 *)(iVar5 + 0x10);
            }
            else if (bVar2 < 3) {
              if (bVar2 == 0) goto _L247;
_L249:
              memcpy(piVar8 + 1,(void *)(iVar5 + 0x12),6);
            }
            else {
              if (bVar2 == 3) goto _L249;
              r_assert_param(bVar2,0,"llm_adv.c",0xf4);
            }
            *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44 + 0x40) = 1;
            r_ble_log_internal_x1(0x404e014f,bStack_3d | 0x100);
            if ((_bt_rf_coex_hooks_p != 0) && (*(code **)(_bt_rf_coex_hooks_p + 4) != (code *)0x0))
            {
              iVar5 = *(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_3d * 0x44);
              uStack_34 = 0;
              uStack_3c = (uint)*(byte *)(iVar5 + 9) << 0x10 | (uint)*(byte *)(iVar5 + 8) << 8 |
                          (uint)*(byte *)(iVar5 + 7);
              uStack_38 = (uint)*(byte *)(iVar5 + 10);
              (**(code **)(_bt_rf_coex_hooks_p + 4))(0,&uStack_3c);
            }
            uVar7 = 0;
            goto _L253;
          }
        }
      }
_L273:
      uVar7 = 0x12;
      goto _L253;
    }
  }
_L235:
  uVar7 = 0xc;
_L253:
  r_llm_cmd_cmp_send(param_2,uVar7);
  return 0;
}

