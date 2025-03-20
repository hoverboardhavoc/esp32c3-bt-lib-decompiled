/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> llm_adv.o -> hci_le_set_adv_en_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_adv_en_cmd_handler(char *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  code *pcVar7;
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
  
  if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    bStack_4a = r_llm_adv_hdl_to_id(0xff,0);
    if (*param_1 != '\0') {
      if (*param_1 == '\x01') {
        iVar3 = r_sdk_config_get_opts();
        if ((uint)bStack_4a < (uint)*(byte *)(iVar3 + 0xd)) {
          if (*(char *)((uint)bStack_4a * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) != '\x01')
          goto _L332;
        }
        else {
          iVar3 = r_llm_activity_free_get(&bStack_4a);
          if (iVar3 != 0) goto _L305;
          r_llm_adv_set_dft_params(bStack_4a);
        }
        bStack_49 = 0;
        iVar2 = *(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_4a * 0x44);
        if (((*(byte *)(iVar2 + 0xb) & 1) == 0) ||
           (iVar3 = r_co_bdaddr_compare(_p_llm_env + 0x12,&co_null_bdaddr), iVar3 == 0)) {
          if ((*(ushort *)(iVar2 + 2) & 1) != 0) {
            iVar3 = r_llm_activity_free_get(&bStack_49);
            if (iVar3 != 0) goto _L305;
            if (((*(ushort *)(iVar2 + 2) & 0xc) != 0) &&
               (iVar3 = r_llm_is_dev_connected(iVar2 + 0xd,*(undefined1 *)(iVar2 + 0xc)), iVar3 != 0
               )) {
              iVar3 = 0xb;
              goto _L305;
            }
          }
          uStack_30 = *(undefined2 *)(iVar2 + 2);
          uStack_3c = (uint)*(byte *)(iVar2 + 9) << 0x10 | (uint)*(byte *)(iVar2 + 8) << 8 |
                      (uint)*(byte *)(iVar2 + 7);
          uStack_2b = *(undefined1 *)(iVar2 + 10);
          bStack_2a = *(byte *)(iVar2 + 0xb);
          uStack_29 = *(undefined1 *)(iVar2 + 0xc);
          bVar1 = bStack_2a & 1;
          memcpy(auStack_42,(void *)(iVar2 + 0xd),6);
          iVar3 = _p_llm_env;
          uStack_28 = *(undefined1 *)(iVar2 + 0x13);
          uStack_27 = *(undefined1 *)(iVar2 + 0x14);
          uStack_26 = *(undefined1 *)(iVar2 + 0x15);
          uStack_25 = *(undefined1 *)(iVar2 + 0x16);
          uStack_23 = *(undefined1 *)(iVar2 + 0x18);
          uStack_22 = *(undefined1 *)(iVar2 + 0x19);
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
          iVar6 = *(int *)(iVar3 + 8) + (uint)bStack_4a * 0x44;
          uStack_38 = *(undefined2 *)(iVar6 + 0x28);
          uStack_34 = *(undefined2 *)(iVar6 + 0x2a);
          uStack_36 = *(undefined2 *)(iVar6 + 0x32);
          uStack_32 = *(undefined2 *)(iVar6 + 0x34);
          uStack_21 = *(undefined1 *)(iVar3 + 0xc6);
          iVar3 = r_lld_adv_start_eco(&uStack_48);
          if (iVar3 != 0) goto _L305;
          iVar6 = *(int *)(_p_llm_env + 8);
          iVar3 = (uint)bStack_4a * 0x44 + iVar6;
          *(undefined1 *)(iVar3 + 0x40) = 2;
          if ((*(ushort *)(iVar2 + 2) & 1) != 0) {
            *(byte *)(iVar3 + 0x3e) = bStack_49;
            *(undefined1 *)(iVar6 + (uint)bStack_49 * 0x44 + 0x40) = 4;
          }
          if ((_bt_rf_coex_hooks_p != (int *)0x0) &&
             (pcVar7 = (code *)*_bt_rf_coex_hooks_p, pcVar7 != (code *)0x0)) {
            uVar4 = 1;
_L353:
            (*pcVar7)(0,uVar4);
          }
          goto _L313;
        }
      }
      iVar3 = 0x12;
      goto _L305;
    }
    iVar3 = r_sdk_config_get_opts();
    uVar5 = (uint)bStack_4a;
    if ((uVar5 < *(byte *)(iVar3 + 0xd)) &&
       (*(char *)(*(int *)(_p_llm_env + 8) + uVar5 * 0x44 + 0x40) == '\x02')) {
      iVar3 = r_lld_adv_stop(uVar5);
      if (iVar3 != 0) goto _L305;
      *(undefined1 *)((uint)bStack_4a * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) = 3;
      if (_bt_rf_coex_hooks_p != (int *)0x0) {
        pcVar7 = (code *)*_bt_rf_coex_hooks_p;
        uVar4 = 0;
        if (pcVar7 != (code *)0x0) goto _L353;
      }
_L313:
      iVar3 = 0;
      if (*param_1 == '\0') {
        return 0;
      }
      goto _L305;
    }
    iVar3 = 0xfe;
    if ((_sdk_cfg_priv_opts & 1) != 0) goto _L305;
  }
_L332:
  iVar3 = 0xc;
_L305:
  r_llm_cmd_cmp_send(param_2,iVar3);
  return 0;
}

