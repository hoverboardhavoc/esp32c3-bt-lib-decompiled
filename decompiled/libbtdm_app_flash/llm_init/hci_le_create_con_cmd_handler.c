/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app_flash -> llm_init.o -> hci_le_create_con_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_create_con_cmd_handler(ushort *param_1,undefined4 param_2)

{
  char cVar1;
  ushort uVar2;
  byte bVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
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
  
  iVar7 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar7 + 0x22) == '\0') {
    r_llm_cmd_stat_send(param_2,0xc);
    return 0;
  }
  bStack_9a = 0;
  if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    while( true ) {
      iVar7 = r_sdk_config_get_opts();
      if (((uint)*(byte *)(iVar7 + 0xd) <= (uint)bStack_9a) ||
         (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_9a * 0x44 + 0x40) == '\x05')) break;
      bStack_9a = bStack_9a + 1;
    }
    iVar7 = r_sdk_config_get_opts();
    if (*(byte *)(iVar7 + 0xd) <= bStack_9a) {
      if ((char)param_1[2] == '\0') {
        iVar7 = r_llm_is_dev_connected(param_1 + 3,*(undefined1 *)((int)param_1 + 5));
        iVar8 = 0xb;
        if (iVar7 != 0) goto _L41;
      }
      bStack_99 = *(byte *)((int)param_1 + 5);
      memcpy(auStack_98,param_1 + 3,6);
      if (*(char *)(_p_llm_env + 0xc6) != '\0') {
        lld_peer_rpa_to_id(auStack_98,&bStack_99);
      }
      if (param_1[1] <= *param_1) {
        uVar9 = (uint)param_1[8];
        if (((((((param_1[7] <= uVar9) && ((ushort)(param_1[1] - 4) < 0x3ffd)) &&
               ((ushort)(*param_1 - 4) < 0x3ffd)) &&
              ((param_1[0xb] <= param_1[0xc] && (5 < param_1[7])))) &&
             ((uVar9 < 0xc81 && (((param_1[10] - 10 & 0xffff) < 0xc77 && (param_1[9] < 500)))))) &&
            (bStack_99 < 4)) &&
           ((((byte)param_1[6] < 4 && ((param_1[9] + 1) * uVar9 < (uint)param_1[10] << 2)) &&
            ((((byte)param_1[6] & 1) == 0 ||
             (iVar7 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar7 == 0)))))) {
          iVar8 = r_llm_activity_free_get(&bStack_9a);
          if (iVar8 != 0) goto _L41;
          uStack_90 = (uint)param_1[7] << 1;
          uVar9 = (uint)param_1[0xb];
          if (uStack_90 < param_1[0xb]) {
            uVar9 = uStack_90;
          }
          if (uVar9 < 2) {
            uVar9 = 2;
          }
          uStack_8c = (uint)param_1[8] << 1;
          uVar11 = (uint)param_1[0xc];
          if (uStack_8c < param_1[0xc]) {
            uVar11 = uStack_8c;
          }
          if (uVar11 < 2) {
            uVar11 = 2;
          }
          uStack_7e = 0;
          uStack_80 = (ushort)bStack_9a;
          uStack_88 = uVar9;
          uStack_84 = uVar11;
          iVar7 = r_sch_plan_req(&uStack_90,0);
          iVar8 = 0xd;
          if (iVar7 != 0) goto _L41;
          if (*(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_9a * 0x44) != 0) {
            r_assert_err("llm_init.c",0xcb);
          }
          uVar4 = (uint)bStack_9a;
          iVar7 = *(int *)(_p_llm_env + 8);
          uVar6 = r_ke_msg_alloc(0,0,0,0x3a);
          *(undefined4 *)(iVar7 + uVar4 * 0x44) = uVar6;
          iVar7 = _p_llm_env;
          puVar10 = (undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_9a * 0x44);
          puVar5 = (undefined1 *)*puVar10;
          if (puVar5 != (undefined1 *)0x0) {
            puVar5[9] = 1;
            *(ushort *)(puVar5 + 10) = *param_1;
            *(ushort *)(puVar5 + 0xc) = param_1[1];
            *puVar5 = (char)param_1[2];
            cVar1 = (char)param_1[6];
            puVar5[1] = cVar1;
            puVar5[2] = bStack_99;
            memcpy(puVar5 + 3,auStack_98,6);
            *(ushort *)(puVar5 + 0xe) = param_1[7];
            *(ushort *)(puVar5 + 0x10) = param_1[8];
            *(ushort *)(puVar5 + 0x12) = param_1[9];
            uVar2 = param_1[10];
            *(short *)(puVar5 + 0x16) = (short)uVar9;
            *(short *)(puVar5 + 0x18) = (short)uVar11;
            *(ushort *)(puVar5 + 0x14) = uVar2;
            if (cVar1 == '\x01') {
_L37:
              memcpy(puVar10 + 1,(void *)(iVar7 + 0x12),6);
            }
            else if ((cVar1 == '\0') || (cVar1 == '\x02')) {
              puVar10[1] = *(undefined4 *)(iVar7 + 0xc);
              *(undefined2 *)(puVar10 + 2) = *(undefined2 *)(iVar7 + 0x10);
            }
            else {
              if (cVar1 == '\x03') goto _L37;
              r_assert_param(cVar1,0,"llm_init.c",0xf5);
            }
          }
          bVar3 = bStack_9a;
          iVar7 = _p_llm_env;
          uVar9 = (uint)bStack_9a;
          iVar8 = uVar9 * 0x44;
          *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar8 + 0x40) = 5;
          memcpy(auStack_6a,auStack_98,6);
          memcpy(auStack_64,(void *)(iVar7 + 0x1d),5);
          uStack_5e = 1;
          uStack_58 = *param_1;
          bStack_5d = bVar3;
          uStack_56 = param_1[1];
          uStack_54 = (undefined2)(uStack_7c >> 1);
          uStack_52 = uStack_78;
          uStack_50 = param_1[9];
          uStack_4e = param_1[10];
          uStack_5c = (undefined1)param_1[6];
          bStack_5b = bStack_99;
          uStack_5a = (undefined1)param_1[2];
          iVar8 = *(int *)(iVar7 + 8) + iVar8;
          uStack_70 = *(undefined4 *)(iVar8 + 4);
          uStack_6c = *(undefined2 *)(iVar8 + 8);
          uStack_5f = 0;
          uStack_34 = *(undefined1 *)(iVar7 + 0xc6);
          if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
             ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
            (*(code *)*_bt_rf_coex_hooks_p)(uVar9,1,1);
          }
          iVar8 = r_lld_init_start_hack(&uStack_70);
          if (iVar8 != 0) {
            iVar8 = 3;
          }
          goto _L41;
        }
      }
      iVar8 = 0x12;
      goto _L41;
    }
  }
  iVar8 = 0xc;
_L41:
  r_llm_cmd_stat_send(param_2,iVar8);
  return 0;
}

