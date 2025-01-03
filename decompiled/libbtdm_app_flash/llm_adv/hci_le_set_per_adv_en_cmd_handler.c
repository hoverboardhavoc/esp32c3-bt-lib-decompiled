/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
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
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
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
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') goto _L765;
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  iVar6 = 0x12;
  if ((1 < *param_1) || (iVar6 = 0x12, 0xef < param_1[1])) goto _L764;
  iVar4 = r_llm_adv_hdl_to_id(0);
  if (iVar4 != 0xff) {
    piVar7 = (int *)(*(int *)(_p_llm_env + 8) + iVar4 * 0x44);
    bVar1 = *(byte *)((int)piVar7 + 0x3d);
    uVar9 = (uint)bVar1;
    if (uVar9 != 0xff) {
      iVar10 = uVar9 * 0x44;
      piVar8 = (int *)(*(int *)(_p_llm_env + 8) + iVar10);
      if ((short)piVar8[0xb] == 0) {
        if (*param_1 == 0) {
          if ((char)piVar8[0x10] == '\v') {
            *(undefined1 *)(piVar8 + 0x10) = 10;
            return 0;
          }
          if ((char)piVar8[0x10] != '\f') {
            iVar6 = 0xfe;
            if ((_sdk_cfg_priv_opts & 0x10) != 0) goto _L764;
            goto _L765;
          }
          iVar6 = r_lld_per_adv_stop(uVar9);
          if (iVar6 == 0) {
            piVar7 = (int *)(*(int *)(_p_llm_env + 8) + iVar4 * 0x44);
            if (((*(ushort *)(*piVar7 + 2) & 3) == 0) && ((char)piVar7[0x10] == '\x02')) {
              r_lld_adv_sync_info_update(iVar4,uVar9,0);
            }
            *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar10 + 0x40) = 0xd;
            if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
               ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
              (*(code *)*_bt_rf_coex_hooks_p)(uVar9,4,0);
            }
          }
          r_sch_plan_rem(*(int *)(_p_llm_env + 8) + iVar10 + 0xc);
          if (iVar6 != 0) goto _L764;
_L791:
          if (*param_1 == 0) {
            return 0;
          }
        }
        else {
          iVar6 = *piVar7;
          uVar2 = *(ushort *)(iVar6 + 2);
          if (((uVar2 & 0x33) != 0) || ((char)piVar8[0x10] == '\r')) goto _L765;
          if ((char)piVar8[0x10] == '\n') {
            *(undefined1 *)(piVar8 + 0x10) = 0xb;
          }
          if ((((uVar2 & 0x13) == 0) && ((char)piVar7[0x10] == '\x02')) &&
             ((char)piVar8[0x10] == '\v')) {
            iVar3 = *piVar8;
            iStack_4c = (uint)*(ushort *)(iVar3 + 4) << 1;
            iStack_50 = (uint)*(ushort *)(iVar3 + 2) << 1;
            uStack_48 = r_llm_per_adv_slot_dur
                                  (*(undefined2 *)((int)piVar8 + 0x2a),*(undefined1 *)(iVar6 + 0x17)
                                  );
            uStack_3e = 0;
            uStack_44 = uStack_48;
            uStack_40 = (ushort)bVar1;
            iVar5 = r_sch_plan_req(&iStack_50);
            if (iVar5 != 0) {
              iVar6 = 0xd;
              goto _L764;
            }
            uStack_5e = *(undefined2 *)(iVar3 + 6);
            uStack_60 = (undefined2)(uStack_3c >> 1);
            uStack_58 = (undefined2)uStack_38;
            uStack_5c = *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar10 + 0x28);
            uStack_56 = *(undefined1 *)(iVar6 + 0xb);
            uStack_55 = *(undefined1 *)(iVar6 + 0x14);
            uStack_54 = *(undefined1 *)(iVar6 + 0x17);
            iVar6 = r_lld_per_adv_start(uVar9,&uStack_60);
            if (iVar6 != 0) goto _L764;
            iVar10 = *(int *)(_p_llm_env + 8) + iVar10;
            *(undefined1 *)(iVar10 + 0x40) = 0xc;
            r_lld_adv_sync_info_update(iVar4,uVar9,uStack_60);
            *(ushort *)(iVar10 + 0x20) = (ushort)bVar1;
            *(undefined4 *)(iVar10 + 0x24) = 0;
            *(undefined4 *)(iVar10 + 0x14) = uStack_38;
            *(undefined1 *)(iVar10 + 0x22) = 0;
            *(uint *)(iVar10 + 0x10) = uStack_3c;
            *(undefined4 *)(iVar10 + 0x18) = uStack_48;
            *(undefined4 *)(iVar10 + 0x1c) = uStack_44;
            r_sch_plan_set(iVar10 + 0xc);
            if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
               ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
              (*(code *)*_bt_rf_coex_hooks_p)(uVar9,4,1);
            }
            goto _L791;
          }
        }
        iVar6 = 0;
      }
      else {
_L765:
        iVar6 = 0xc;
      }
      goto _L764;
    }
  }
  iVar6 = 0x42;
_L764:
  r_llm_cmd_cmp_send(param_2,iVar6);
  return 0;
}

