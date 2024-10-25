/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  byte bStack_91;
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
  undefined1 uStack_5b;
  undefined1 uStack_5a;
  ushort uStack_58;
  ushort uStack_56;
  undefined2 uStack_54;
  undefined2 uStack_52;
  ushort uStack_50;
  ushort uStack_4e;
  undefined1 uStack_34;
  
  iVar8 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar8 + 0x22) == '\0') {
    r_llm_cmd_stat_send(param_2,0xc);
    return 0;
  }
  bStack_91 = 0;
  if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    while( true ) {
      iVar8 = r_sdk_config_get_opts();
      if (((uint)*(byte *)(iVar8 + 0xd) <= (uint)bStack_91) ||
         (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_91 * 0x44 + 0x40) == '\x05')) break;
      bStack_91 = bStack_91 + 1;
    }
    iVar8 = r_sdk_config_get_opts();
    if (*(byte *)(iVar8 + 0xd) <= bStack_91) {
      if ((char)param_1[2] == '\0') {
        iVar6 = r_llm_is_dev_connected(param_1 + 3,*(undefined1 *)((int)param_1 + 5));
        iVar8 = 0xb;
        if (iVar6 != 0) goto _L39;
      }
      if (param_1[1] <= *param_1) {
        uVar9 = (uint)param_1[8];
        if (((((((param_1[7] <= uVar9) && ((ushort)(param_1[1] - 4) < 0x3ffd)) &&
               ((ushort)(*param_1 - 4) < 0x3ffd)) &&
              ((param_1[0xb] <= param_1[0xc] && (5 < param_1[7])))) &&
             ((uVar9 < 0xc81 && (((param_1[10] - 10 & 0xffff) < 0xc77 && (param_1[9] < 500)))))) &&
            (*(byte *)((int)param_1 + 5) < 4)) &&
           ((((byte)param_1[6] < 4 && ((param_1[9] + 1) * uVar9 < (uint)param_1[10] << 2)) &&
            ((((byte)param_1[6] & 1) == 0 ||
             (iVar8 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar8 == 0)))))) {
          iVar8 = r_llm_activity_free_get(&bStack_91);
          if (iVar8 != 0) goto _L39;
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
          uStack_80 = (ushort)bStack_91;
          uStack_88 = uVar9;
          uStack_84 = uVar11;
          iVar6 = r_sch_plan_req(&uStack_90,0);
          iVar8 = 0xd;
          if (iVar6 != 0) goto _L39;
          if (*(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_91 * 0x44) != 0) {
            r_assert_err("llm_init.c",0xc3);
          }
          uVar4 = (uint)bStack_91;
          iVar8 = *(int *)(_p_llm_env + 8);
          uVar7 = r_ke_msg_alloc(0,0,0,0x3a);
          *(undefined4 *)(iVar8 + uVar4 * 0x44) = uVar7;
          iVar8 = _p_llm_env;
          puVar10 = (undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_91 * 0x44);
          puVar5 = (undefined1 *)*puVar10;
          if (puVar5 != (undefined1 *)0x0) {
            puVar5[9] = 1;
            *(ushort *)(puVar5 + 10) = *param_1;
            *(ushort *)(puVar5 + 0xc) = param_1[1];
            *puVar5 = (char)param_1[2];
            cVar1 = (char)param_1[6];
            puVar5[1] = cVar1;
            puVar5[2] = *(undefined1 *)((int)param_1 + 5);
            memcpy(puVar5 + 3,param_1 + 3,6);
            *(ushort *)(puVar5 + 0xe) = param_1[7];
            *(ushort *)(puVar5 + 0x10) = param_1[8];
            *(ushort *)(puVar5 + 0x12) = param_1[9];
            uVar2 = param_1[10];
            *(short *)(puVar5 + 0x16) = (short)uVar9;
            *(short *)(puVar5 + 0x18) = (short)uVar11;
            *(ushort *)(puVar5 + 0x14) = uVar2;
            if (cVar1 == '\x01') {
_L35:
              memcpy(puVar10 + 1,(void *)(iVar8 + 0x12),6);
            }
            else if ((cVar1 == '\0') || (cVar1 == '\x02')) {
              puVar10[1] = *(undefined4 *)(iVar8 + 0xc);
              *(undefined2 *)(puVar10 + 2) = *(undefined2 *)(iVar8 + 0x10);
            }
            else {
              if (cVar1 == '\x03') goto _L35;
              r_assert_param(cVar1,0,"llm_init.c",0xed);
            }
          }
          bVar3 = bStack_91;
          iVar8 = _p_llm_env;
          uVar9 = (uint)bStack_91;
          iVar6 = uVar9 * 0x44;
          *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar6 + 0x40) = 5;
          memcpy(auStack_6a,param_1 + 3,6);
          memcpy(auStack_64,(void *)(iVar8 + 0x1d),5);
          uStack_5e = 1;
          uStack_58 = *param_1;
          bStack_5d = bVar3;
          uStack_56 = param_1[1];
          uStack_54 = (undefined2)(uStack_7c >> 1);
          uStack_52 = uStack_78;
          uStack_50 = param_1[9];
          uStack_4e = param_1[10];
          uStack_5c = (undefined1)param_1[6];
          uStack_5b = *(undefined1 *)((int)param_1 + 5);
          uStack_5a = (undefined1)param_1[2];
          iVar6 = *(int *)(iVar8 + 8) + iVar6;
          uStack_70 = *(undefined4 *)(iVar6 + 4);
          uStack_6c = *(undefined2 *)(iVar6 + 8);
          uStack_5f = 0;
          uStack_34 = *(undefined1 *)(iVar8 + 0xc6);
          if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
             ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
            (*(code *)*_bt_rf_coex_hooks_p)(uVar9,1,1);
          }
          iVar8 = r_lld_init_start_hack(&uStack_70);
          if (iVar8 != 0) {
            iVar8 = 3;
          }
          goto _L39;
        }
      }
      iVar8 = 0x12;
      goto _L39;
    }
  }
  iVar8 = 0xc;
_L39:
  r_llm_cmd_stat_send(param_2,iVar8);
  return 0;
}

