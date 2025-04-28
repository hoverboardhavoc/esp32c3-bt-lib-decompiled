/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_init.o -> hci_le_create_con_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_create_con_cmd_handler(ushort *param_1,undefined4 param_2)

{
  byte bVar1;
  ushort uVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
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
  
  iVar5 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar5 + 0x22) == '\0') {
    r_llm_cmd_stat_send(param_2,0xc);
    return 0;
  }
  bStack_9a = 0;
  if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    while( true ) {
      iVar5 = r_sdk_config_get_opts();
      if (((uint)*(byte *)(iVar5 + 0xd) <= (uint)bStack_9a) ||
         (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_9a * 0x44 + 0x40) == '\x05')) break;
      bStack_9a = bStack_9a + 1;
    }
    iVar5 = r_sdk_config_get_opts();
    if (*(byte *)(iVar5 + 0xd) <= bStack_9a) {
      if ((char)param_1[2] == '\0') {
        iVar5 = r_llm_is_dev_connected(param_1 + 3,*(undefined1 *)((int)param_1 + 5));
        iVar6 = 0xb;
        if (iVar5 != 0) goto _L42;
      }
      bStack_99 = *(byte *)((int)param_1 + 5);
      memcpy(auStack_98,param_1 + 3,6);
      if (*(char *)(_p_llm_env + 0xc6) != '\0') {
        lld_peer_rpa_to_id(auStack_98,&bStack_99);
      }
      if (param_1[1] <= *param_1) {
        uVar7 = (uint)param_1[8];
        if (((((((param_1[7] <= uVar7) && ((ushort)(param_1[1] - 4) < 0x3ffd)) &&
               ((ushort)(*param_1 - 4) < 0x3ffd)) &&
              ((param_1[0xb] <= param_1[0xc] && (5 < param_1[7])))) &&
             ((uVar7 < 0xc81 && (((param_1[10] - 10 & 0xffff) < 0xc77 && (param_1[9] < 500)))))) &&
            (bStack_99 < 4)) &&
           ((((byte)param_1[6] < 4 && ((ushort)(param_1[9] + 1) * uVar7 < (uint)param_1[10] << 2))
            && ((((byte)param_1[6] & 1) == 0 ||
                (iVar5 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar5 == 0)))))) {
          iVar6 = r_llm_activity_free_get(&bStack_9a);
          if (iVar6 != 0) goto _L42;
          uStack_90 = (uint)param_1[7] << 1;
          uVar7 = (uint)param_1[0xb];
          if (uStack_90 < param_1[0xb]) {
            uVar7 = uStack_90;
          }
          if (uVar7 < 2) {
            uVar7 = 2;
          }
          uStack_8c = (uint)param_1[8] << 1;
          uVar9 = (uint)param_1[0xc];
          if (uStack_8c < param_1[0xc]) {
            uVar9 = uStack_8c;
          }
          if (uVar9 < 2) {
            uVar9 = 2;
          }
          uStack_7e = 0;
          uStack_80 = (ushort)bStack_9a;
          uStack_88 = uVar7;
          uStack_84 = uVar9;
          iVar5 = r_sch_plan_req(&uStack_90,0);
          iVar6 = 0xd;
          if (iVar5 != 0) goto _L42;
          if (*(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_9a * 0x44) != 0) {
            r_assert_err(0x10000,0xcb);
          }
          uVar8 = (uint)bStack_9a;
          iVar5 = *(int *)(_p_llm_env + 8);
          uVar4 = r_ke_msg_alloc(0,0,0,0x3a);
          *(undefined4 *)(iVar5 + uVar8 * 0x44) = uVar4;
          iVar5 = _p_llm_env;
          iVar6 = *(int *)(_p_llm_env + 8);
          puVar3 = *(undefined1 **)((uint)bStack_9a * 0x44 + iVar6);
          if (puVar3 != (undefined1 *)0x0) {
            puVar3[9] = 1;
            *(ushort *)(puVar3 + 10) = *param_1;
            *(ushort *)(puVar3 + 0xc) = param_1[1];
            *puVar3 = (char)param_1[2];
            bVar1 = (byte)param_1[6];
            puVar3[1] = bVar1;
            puVar3[2] = bStack_99;
            memcpy(puVar3 + 3,auStack_98,6);
            *(ushort *)(puVar3 + 0xe) = param_1[7];
            *(ushort *)(puVar3 + 0x10) = param_1[8];
            *(ushort *)(puVar3 + 0x12) = param_1[9];
            uVar2 = param_1[10];
            *(short *)(puVar3 + 0x16) = (short)uVar7;
            *(short *)(puVar3 + 0x18) = (short)uVar9;
            *(ushort *)(puVar3 + 0x14) = uVar2;
            if (bVar1 == 2) {
_L37:
              iVar6 = (uint)bStack_9a * 0x44 + iVar6;
              *(undefined4 *)(iVar6 + 4) = *(undefined4 *)(iVar5 + 0xc);
              *(undefined2 *)(iVar6 + 8) = *(undefined2 *)(iVar5 + 0x10);
            }
            else {
              if (bVar1 < 3) {
                if (bVar1 == 0) goto _L37;
              }
              else if (bVar1 != 3) {
                r_assert_param(bVar1,0,0x10000,0xf5);
                goto _L36;
              }
              memcpy((void *)(iVar6 + (uint)bStack_9a * 0x44 + 4),(void *)(iVar5 + 0x12),6);
            }
          }
_L36:
          bVar1 = bStack_9a;
          iVar5 = _p_llm_env;
          uVar7 = (uint)bStack_9a;
          iVar6 = uVar7 * 0x44;
          *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar6 + 0x40) = 5;
          memcpy(auStack_6a,auStack_98,6);
          memcpy(auStack_64,(void *)(iVar5 + 0x1d),5);
          uStack_5e = 1;
          uStack_58 = *param_1;
          bStack_5d = bVar1;
          uStack_56 = param_1[1];
          uStack_54 = (undefined2)(uStack_7c >> 1);
          uStack_52 = uStack_78;
          uStack_50 = param_1[9];
          uStack_4e = param_1[10];
          uStack_5c = (undefined1)param_1[6];
          bStack_5b = bStack_99;
          uStack_5a = (undefined1)param_1[2];
          iVar6 = *(int *)(iVar5 + 8) + iVar6;
          uStack_70 = *(undefined4 *)(iVar6 + 4);
          uStack_6c = *(undefined2 *)(iVar6 + 8);
          uStack_5f = 0;
          uStack_34 = *(undefined1 *)(iVar5 + 0xc6);
          if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
             ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
            (*(code *)*_bt_rf_coex_hooks_p)(uVar7,1,1);
          }
          iVar6 = r_lld_init_start_hack(&uStack_70);
          if (iVar6 != 0) {
            iVar6 = 3;
          }
          goto _L42;
        }
      }
      iVar6 = 0x12;
      goto _L42;
    }
  }
  iVar6 = 0xc;
_L42:
  r_llm_cmd_stat_send(param_2,iVar6);
  return 0;
}

