/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llm_adv.o -> hci_le_set_per_adv_en_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_per_adv_en_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  undefined2 uStack_60;
  undefined2 uStack_5e;
  undefined4 uStack_5c;
  undefined2 uStack_58;
  undefined1 uStack_56;
  undefined1 uStack_55;
  undefined1 uStack_54;
  int iStack_50;
  int iStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  ushort uStack_40;
  undefined2 uStack_3e;
  uint uStack_3c;
  undefined4 uStack_38;
  
  iVar6 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar6 + 0x18) == '\0') {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') goto _L886;
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  iVar6 = 0x12;
  if ((1 < *param_1) || (0xef < param_1[1])) goto _L843;
  iVar4 = r_llm_adv_hdl_to_id(0);
  if (iVar4 == 0xff) {
    uVar7 = 0xff42;
    uVar5 = 0x802e011d;
  }
  else {
    iVar11 = iVar4 * 0x44;
    piVar8 = (int *)(*(int *)(_p_llm_env + 8) + iVar11);
    bVar1 = *(byte *)((int)piVar8 + 0x3d);
    uVar7 = (uint)bVar1;
    if (uVar7 != 0xff) {
      iVar10 = uVar7 * 0x44;
      iVar6 = *(int *)(_p_llm_env + 8) + iVar10;
      if (*(ushort *)(iVar6 + 0x2c) == 0) {
        if (*param_1 == 0) {
          if (*(char *)(iVar6 + 0x40) == '\v') {
            *(undefined1 *)(iVar6 + 0x40) = 10;
            r_ble_log_internal_x1(0x404e0125,uVar7 | 0xa00);
          }
          else {
            if (*(char *)(iVar6 + 0x40) != '\f') {
              iVar6 = 0xfe;
              if ((_sdk_cfg_priv_opts & 0x10) != 0) goto _L843;
              goto _L886;
            }
            iVar6 = r_lld_per_adv_stop(uVar7);
            if (iVar6 == 0) {
              piVar8 = (int *)(*(int *)(_p_llm_env + 8) + iVar11);
              if (((*(ushort *)(*piVar8 + 2) & 3) == 0) && ((char)piVar8[0x10] == '\x02')) {
                r_lld_adv_sync_info_update(iVar4,uVar7,0);
              }
              *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar10 + 0x40) = 0xd;
              r_ble_log_internal_x1(0x404e0126,uVar7 | 0xd00);
              if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
                 ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
                (*(code *)*_bt_rf_coex_hooks_p)(uVar7,4,0);
              }
            }
            r_sch_plan_rem(*(int *)(_p_llm_env + 8) + iVar10 + 0xc);
            if (iVar6 != 0) goto _L843;
          }
_L852:
          if (*param_1 == 0) {
            return 0;
          }
          iVar6 = 0;
          goto _L843;
        }
        iVar3 = *piVar8;
        uVar2 = *(ushort *)(iVar3 + 2);
        if ((uVar2 & 0x33) == 0) {
          if (*(char *)(iVar6 + 0x40) != '\r') {
            if (*(char *)(iVar6 + 0x40) == '\n') {
              *(undefined1 *)(iVar6 + 0x40) = 0xb;
              r_ble_log_internal_x1(0x404e0122,uVar7 | 0xb00);
            }
            if ((*(ushort *)(iVar3 + 2) & 0x13) == 0) {
              piVar8 = (int *)(iVar11 + *(int *)(_p_llm_env + 8));
              if (((char)piVar8[0x10] == '\x02') &&
                 (piVar9 = (int *)(*(int *)(_p_llm_env + 8) + iVar10), (char)piVar9[0x10] == '\v'))
              {
                iVar3 = *piVar9;
                iVar6 = *piVar8;
                iStack_4c = (uint)*(ushort *)(iVar3 + 4) << 1;
                iStack_50 = (uint)*(ushort *)(iVar3 + 2) << 1;
                uStack_48 = r_llm_per_adv_slot_dur
                                      (*(undefined2 *)((int)piVar9 + 0x2a),
                                       *(undefined1 *)(iVar6 + 0x17));
                uStack_3e = 0;
                uStack_44 = uStack_48;
                uStack_40 = (ushort)bVar1;
                iVar11 = r_sch_plan_req(&iStack_50);
                if (iVar11 != 0) {
                  r_ble_log_internal_x3(0x802e0123,iStack_4c,uStack_48,uVar7 << 8 | 0xd);
                  iVar6 = 0xd;
                  goto _L843;
                }
                uStack_5e = *(undefined2 *)(iVar3 + 6);
                uStack_60 = (undefined2)(uStack_3c >> 1);
                uStack_58 = (undefined2)uStack_38;
                uStack_5c = *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar10 + 0x28);
                uStack_56 = *(undefined1 *)(iVar6 + 0xb);
                uStack_55 = *(undefined1 *)(iVar6 + 0x14);
                uStack_54 = *(undefined1 *)(iVar6 + 0x17);
                iVar6 = r_lld_per_adv_start(uVar7,&uStack_60);
                if (iVar6 != 0) goto _L843;
                iVar10 = *(int *)(_p_llm_env + 8) + iVar10;
                *(undefined1 *)(iVar10 + 0x40) = 0xc;
                r_ble_log_internal_x1(0x404e0124,uVar7 | 0xc00);
                r_lld_adv_sync_info_update(iVar4,uVar7,uStack_60);
                *(ushort *)(iVar10 + 0x20) = (ushort)bVar1;
                *(undefined4 *)(iVar10 + 0x24) = 0;
                *(undefined4 *)(iVar10 + 0x14) = uStack_38;
                *(undefined1 *)(iVar10 + 0x22) = 0;
                *(uint *)(iVar10 + 0x10) = uStack_3c;
                *(undefined4 *)(iVar10 + 0x18) = uStack_48;
                *(undefined4 *)(iVar10 + 0x1c) = uStack_44;
                r_sch_plan_set_hack(iVar10 + 0xc);
                if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
                   ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
                  (*(code *)*_bt_rf_coex_hooks_p)(uVar7,4,1);
                }
              }
            }
            goto _L852;
          }
          uVar7 = uVar7 << 8 | 0xd000c;
          uVar5 = 0x802e0121;
        }
        else {
          uVar7 = uVar2 | 0xc0000;
          uVar5 = 0x802e0120;
        }
        r_ble_log_internal_x1(uVar5,uVar7);
      }
      else {
        r_ble_log_internal_x2
                  (0x802e011f,iVar4 << 0x18 | (uint)*(ushort *)(iVar6 + 0x2c) | 0xc0000,uVar7);
      }
_L886:
      iVar6 = 0xc;
      goto _L843;
    }
    uVar7 = iVar4 << 8 | 0xff0042;
    uVar5 = 0x802e011e;
  }
  r_ble_log_internal_x1(uVar5,uVar7);
  iVar6 = 0x42;
_L843:
  r_llm_cmd_cmp_send(param_2,iVar6);
  return 0;
}

