/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm_adv.o -> hci_le_set_adv_en_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_adv_en_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  code *pcVar8;
  byte bStack_4a;
  byte bStack_49;
  undefined4 uStack_48;
  undefined2 uStack_44;
  undefined1 auStack_42 [6];
  uint uStack_3c;
  undefined2 uStack_38;
  undefined2 uStack_36;
  undefined2 uStack_34;
  undefined2 uStack_32;
  undefined2 uStack_30;
  undefined2 uStack_2e;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  byte bStack_2a;
  undefined1 uStack_29;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_25;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 uStack_21;
  
  if ((*(char *)(_p_llm_env + 0xd7) == '\x02') ||
     (iVar3 = r_sdk_config_get_opts_ext(), *(char *)(iVar3 + 0x25) == '\0')) {
_L372:
    uVar2 = 0xc;
    goto _L310;
  }
  *(undefined1 *)(_p_llm_env + 0xd7) = 1;
  bStack_4a = r_llm_adv_hdl_to_id(0xff,0);
  if (*param_1 == 0) {
    iVar3 = r_sdk_config_get_opts();
    uVar6 = (uint)bStack_4a;
    if ((uVar6 < *(byte *)(iVar3 + 0xd)) &&
       (*(char *)(*(int *)(_p_llm_env + 8) + uVar6 * 0x44 + 0x40) == '\x02')) {
      uVar2 = r_lld_adv_stop(uVar6);
      uVar6 = (uint)bStack_4a;
      iVar3 = *(int *)(_p_llm_env + 8) + uVar6 * 0x44;
      if (uVar2 == 0) {
        *(undefined1 *)(iVar3 + 0x40) = 3;
        r_ble_log_internal_x1(0x404e0159,uVar6 | 0x300);
        if (_bt_rf_coex_hooks_p != (int *)0x0) {
          pcVar8 = (code *)*_bt_rf_coex_hooks_p;
          uVar5 = 0;
          if (pcVar8 != (code *)0x0) goto _L371;
        }
        goto _L319;
      }
      uVar6 = uVar6 << 8 | (uint)*(byte *)(iVar3 + 0x40) << 0x18 | (uint)*param_1 << 0x10 | uVar2;
      uVar5 = 0x802e015a;
    }
    else {
      uVar2 = 0xc;
      if ((_sdk_cfg_priv_opts & 1) != 0) {
        uVar2 = 0xfe;
      }
      uVar6 = uVar6 << 8 | uVar2;
      uVar5 = 0x802e0158;
    }
_L373:
    r_ble_log_internal_x1(uVar5,uVar6);
  }
  else {
    if (*param_1 == 1) {
      iVar3 = r_sdk_config_get_opts();
      uVar6 = (uint)bStack_4a;
      if (uVar6 < *(byte *)(iVar3 + 0xd)) {
        uVar2 = (uint)*(byte *)(*(int *)(_p_llm_env + 8) + uVar6 * 0x44 + 0x40);
        if (uVar2 != 1) {
          r_ble_log_internal_x1(0x802e015b,uVar6 << 8 | uVar2 << 0x10 | 0xc);
          goto _L372;
        }
      }
      else {
        uVar2 = r_llm_activity_free_get(&bStack_4a);
        if (uVar2 != 0) {
          uVar6 = (uint)bStack_4a << 8 | uVar2;
          uVar5 = 0x802e015c;
          goto _L373;
        }
        r_llm_adv_set_dft_params();
      }
      bStack_49 = 0;
      iVar3 = *(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_4a * 0x44);
      if (((*(byte *)(iVar3 + 0xb) & 1) == 0) ||
         (iVar4 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar4 == 0)) {
        if ((*(ushort *)(iVar3 + 2) & 1) != 0) {
          uVar2 = r_llm_activity_free_get(&bStack_49);
          if (uVar2 != 0) {
            uVar6 = (uint)bStack_49 << 8 | uVar2;
            uVar5 = 0x802e015e;
            goto _L373;
          }
          if (((*(ushort *)(iVar3 + 2) & 0xc) != 0) &&
             (iVar4 = r_llm_is_dev_connected(iVar3 + 0xd,*(undefined1 *)(iVar3 + 0xc)), iVar4 != 0))
          {
            r_ble_log_internal_x1(0x802e015f,(uint)bStack_4a << 8 | 0xb);
            uVar2 = 0xb;
            goto _L310;
          }
        }
        uStack_30 = *(undefined2 *)(iVar3 + 2);
        uStack_3c = (uint)*(byte *)(iVar3 + 9) << 0x10 | (uint)*(byte *)(iVar3 + 8) << 8 |
                    (uint)*(byte *)(iVar3 + 7);
        uStack_2b = *(undefined1 *)(iVar3 + 10);
        bStack_2a = *(byte *)(iVar3 + 0xb);
        uStack_29 = *(undefined1 *)(iVar3 + 0xc);
        bVar1 = bStack_2a & 1;
        memcpy(auStack_42,(void *)(iVar3 + 0xd),6);
        iVar4 = _p_llm_env;
        uStack_28 = *(undefined1 *)(iVar3 + 0x13);
        uStack_27 = *(undefined1 *)(iVar3 + 0x14);
        uStack_26 = *(undefined1 *)(iVar3 + 0x15);
        uStack_25 = *(undefined1 *)(iVar3 + 0x16);
        uStack_23 = *(undefined1 *)(iVar3 + 0x18);
        uStack_22 = *(undefined1 *)(iVar3 + 0x19);
        uStack_24 = uStack_26;
        if (bVar1 == 0) {
          uStack_48 = *(undefined4 *)(_p_llm_env + 0xc);
          uStack_44 = *(undefined2 *)(_p_llm_env + 0x10);
        }
        else {
          memcpy(&uStack_48,(void *)(_p_llm_env + 0x12),6);
        }
        uStack_2e = 0;
        uStack_2c = 0;
        iVar7 = *(int *)(iVar4 + 8) + (uint)bStack_4a * 0x44;
        uStack_38 = *(undefined2 *)(iVar7 + 0x28);
        uStack_34 = *(undefined2 *)(iVar7 + 0x2a);
        uStack_36 = *(undefined2 *)(iVar7 + 0x32);
        uStack_32 = *(undefined2 *)(iVar7 + 0x34);
        uStack_21 = *(undefined1 *)(iVar4 + 0xc6);
        uVar2 = r_lld_adv_start_eco(&uStack_48);
        if (uVar2 != 0) goto _L310;
        *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_4a * 0x44 + 0x40) = 2;
        r_ble_log_internal_x1(0x404e0160,bStack_4a | 0x200);
        if ((*(ushort *)(iVar3 + 2) & 1) != 0) {
          iVar3 = *(int *)(_p_llm_env + 8);
          *(byte *)((uint)bStack_4a * 0x44 + iVar3 + 0x3e) = bStack_49;
          *(undefined1 *)(iVar3 + (uint)bStack_49 * 0x44 + 0x40) = 4;
        }
        if ((_bt_rf_coex_hooks_p != (int *)0x0) &&
           (pcVar8 = (code *)*_bt_rf_coex_hooks_p, pcVar8 != (code *)0x0)) {
          uVar5 = 1;
_L371:
          (*pcVar8)(bStack_4a,0,uVar5);
        }
_L319:
        if (*param_1 == 0) {
          return 0;
        }
        uVar2 = 0;
        goto _L310;
      }
      r_ble_log_internal_x1(0x802e015d,(uint)*(byte *)(iVar3 + 0xb) << 8 | 0x12);
    }
    uVar2 = 0x12;
  }
_L310:
  r_llm_cmd_cmp_send(param_2,uVar2);
  return 0;
}

