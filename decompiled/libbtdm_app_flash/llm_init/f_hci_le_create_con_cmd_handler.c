/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llm_init.o -> f_hci_le_create_con_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_create_con_cmd_handler(ushort *param_1,undefined4 param_2)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  byte bStack_9a;
  byte bStack_99;
  undefined1 auStack_98 [8];
  uint uStack_90;
  uint uStack_8c;
  uint uStack_88;
  uint uStack_84;
  ushort uStack_80;
  undefined2 uStack_7e;
  uint uStack_7c;
  undefined2 uStack_78;
  undefined4 uStack_70;
  undefined2 uStack_6c;
  undefined1 auStack_6a [6];
  undefined1 auStack_64 [5];
  undefined1 uStack_5f;
  undefined1 uStack_5e;
  byte bStack_5d;
  undefined1 uStack_5c;
  byte bStack_5b;
  undefined1 uStack_5a;
  ushort uStack_58;
  ushort uStack_56;
  undefined2 uStack_54;
  undefined2 uStack_52;
  ushort uStack_50;
  ushort uStack_4e;
  undefined1 uStack_34;
  
  bStack_9a = 0;
  if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    while( true ) {
      iVar5 = r_sdk_config_get_opts();
      if ((uint)*(byte *)(iVar5 + 0xd) <= (uint)bStack_9a) break;
      if (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_9a * 0x44 + 0x40) == '\x05') break;
      bStack_9a = bStack_9a + 1;
    }
    iVar5 = r_sdk_config_get_opts();
    if ((uint)*(byte *)(iVar5 + 0xd) <= (uint)bStack_9a) {
      if (((char)param_1[2] == '\0') &&
         (iVar5 = r_llm_is_dev_connected(param_1 + 3,*(undefined1 *)((int)param_1 + 5)), iVar5 != 0)
         ) {
        r_ble_log_internal_x1(0x802e01da,(uint)(byte)param_1[2] << 8 | 0xb);
        uVar3 = 0xb;
        goto _L40;
      }
      bStack_99 = *(byte *)((int)param_1 + 5);
      memcpy(auStack_98,param_1 + 3,6);
      if (*(char *)(_p_llm_env + 0xc6) != '\0') {
        lld_peer_rpa_to_id(auStack_98,&bStack_99);
      }
      if (*param_1 < param_1[1]) {
_L24:
        uVar3 = 0x12;
        uVar6 = 0x802e01db;
      }
      else {
        uVar3 = (uint)param_1[8];
        if ((((((uVar3 < param_1[7]) || (0x3ffc < (ushort)(param_1[1] - 4))) ||
              (0x3ffc < (ushort)(*param_1 - 4))) ||
             ((param_1[0xc] < param_1[0xb] || ((uint)param_1[7] < (uint)_g_ble_con_interval_min))))
            || ((0xc80 < uVar3 || ((0xc76 < (param_1[10] - 10 & 0xffff) || (499 < param_1[9]))))))
           || (3 < bStack_99)) goto _L24;
        if (3 < (byte)param_1[6]) goto _L24;
        if ((uint)param_1[10] << 2 <= (ushort)(param_1[9] + 1) * uVar3) goto _L24;
        if ((((byte)param_1[6] & 1) == 0) ||
           (iVar5 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar5 == 0)) {
          uVar3 = r_llm_activity_free_get(&bStack_9a);
          if (uVar3 != 0) {
            r_ble_log_internal_x1(0x802e01dd,(uint)bStack_9a << 8 | uVar3);
            goto _L40;
          }
          uStack_90 = (uint)param_1[7] << 1;
          uStack_8c = (uint)param_1[8] << 1;
          uVar3 = (uint)param_1[0xb];
          if (uStack_90 < param_1[0xb]) {
            uVar3 = uStack_90;
          }
          if (uVar3 < 5) {
            uVar3 = 5;
          }
          uVar8 = (uint)param_1[0xc];
          if (uStack_8c < param_1[0xc]) {
            uVar8 = uStack_8c;
          }
          if (uVar8 < 5) {
            uVar8 = 5;
          }
          uStack_7e = 0;
          uStack_80 = (ushort)bStack_9a;
          uStack_88 = uVar3;
          uStack_84 = uVar8;
          iVar5 = r_sch_plan_req(&uStack_90);
          if (iVar5 != 0) {
            r_ble_log_internal_x1(0x802e01de,(uint)bStack_9a << 8 | 0xd);
            uVar3 = 0xd;
            goto _L40;
          }
          if (*(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_9a * 0x44) != 0) {
            r_assert_err(0x10000,0xda);
          }
          uVar7 = (uint)bStack_9a;
          iVar5 = *(int *)(_p_llm_env + 8);
          uVar6 = r_ke_msg_alloc(0,0,0,0x3a);
          *(undefined4 *)(iVar5 + uVar7 * 0x44) = uVar6;
          iVar5 = _p_llm_env;
          iVar9 = *(int *)(_p_llm_env + 8);
          puVar4 = *(undefined1 **)((uint)bStack_9a * 0x44 + iVar9);
          if (puVar4 != (undefined1 *)0x0) {
            puVar4[9] = 1;
            *(ushort *)(puVar4 + 10) = *param_1;
            *(ushort *)(puVar4 + 0xc) = param_1[1];
            *puVar4 = (char)param_1[2];
            bVar1 = (byte)param_1[6];
            puVar4[1] = bVar1;
            puVar4[2] = bStack_99;
            memcpy(puVar4 + 3,auStack_98,6);
            *(ushort *)(puVar4 + 0xe) = param_1[7];
            *(ushort *)(puVar4 + 0x10) = param_1[8];
            *(ushort *)(puVar4 + 0x12) = param_1[9];
            uVar2 = param_1[10];
            *(short *)(puVar4 + 0x16) = (short)uVar3;
            *(short *)(puVar4 + 0x18) = (short)uVar8;
            *(ushort *)(puVar4 + 0x14) = uVar2;
            if (bVar1 == 2) {
_L35:
              iVar9 = (uint)bStack_9a * 0x44 + iVar9;
              *(undefined4 *)(iVar9 + 4) = *(undefined4 *)(iVar5 + 0xc);
              *(undefined2 *)(iVar9 + 8) = *(undefined2 *)(iVar5 + 0x10);
            }
            else {
              if (bVar1 < 3) {
                if (bVar1 == 0) goto _L35;
              }
              else if (bVar1 != 3) {
                r_assert_param(bVar1,0,0x10000,0x104);
                goto _L34;
              }
              memcpy((void *)(iVar9 + (uint)bStack_9a * 0x44 + 4),(void *)(iVar5 + 0x12),6);
            }
          }
_L34:
          *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_9a * 0x44 + 0x40) = 5;
          r_ble_log_internal_x1(0x404e01df,bStack_9a | 0x500);
          memcpy(auStack_6a,auStack_98,6);
          iVar5 = _p_llm_env;
          memcpy(auStack_64,(void *)(_p_llm_env + 0x1d),5);
          uStack_5e = 1;
          uStack_58 = *param_1;
          uStack_56 = param_1[1];
          bStack_5d = bStack_9a;
          uStack_54 = (undefined2)(uStack_7c >> 1);
          uStack_52 = uStack_78;
          uStack_50 = param_1[9];
          uStack_4e = param_1[10];
          uStack_5c = (undefined1)param_1[6];
          bStack_5b = bStack_99;
          uStack_5a = (undefined1)param_1[2];
          iVar9 = *(int *)(iVar5 + 8) + (uint)bStack_9a * 0x44;
          uStack_70 = *(undefined4 *)(iVar9 + 4);
          uStack_6c = *(undefined2 *)(iVar9 + 8);
          uStack_5f = 0;
          uStack_34 = *(undefined1 *)(iVar5 + 0xc6);
          if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
             ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
            (*(code *)*_bt_rf_coex_hooks_p)(1,1);
          }
          uVar3 = r_lld_init_start_hack(&uStack_70);
          if (uVar3 != 0) {
            r_ble_log_internal_x1(0x802e01e0,uVar3);
            uVar3 = 3;
          }
          goto _L40;
        }
        uVar6 = 0x802e01dc;
        uVar3 = (uint)(byte)param_1[6] << 8 | 0x12;
      }
      r_ble_log_internal_x1(uVar6,uVar3);
      uVar3 = 0x12;
      goto _L40;
    }
    r_ble_log_internal_x1(0x802e01d9,(uint)bStack_9a << 8 | 0xc);
  }
  uVar3 = 0xc;
_L40:
  r_llm_cmd_stat_send(param_2,uVar3);
  return 0;
}

