/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_adv.o -> f_hci_le_set_per_adv_en_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_per_adv_en_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  undefined2 local_60;
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
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') goto _L769;
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  iVar9 = 0x12;
  if ((1 < *param_1) || (iVar9 = 0x12, 0xef < param_1[1])) goto _L768;
  iVar4 = r_llm_adv_hdl_to_id(0);
  if (iVar4 != 0xff) {
    piVar6 = (int *)(*(int *)(_p_llm_env + 8) + iVar4 * 0x44);
    bVar1 = *(byte *)((int)piVar6 + 0x3d);
    uVar3 = (uint)bVar1;
    if (uVar3 != 0xff) {
      iVar8 = uVar3 * 0x44;
      piVar7 = (int *)(*(int *)(_p_llm_env + 8) + iVar8);
      if ((short)piVar7[0xb] == 0) {
        if (*param_1 == 0) {
          if ((char)piVar7[0x10] == '\v') {
            *(undefined1 *)(piVar7 + 0x10) = 10;
            return 0;
          }
          if ((char)piVar7[0x10] != '\f') {
            iVar9 = 0xfe;
            if ((_sdk_cfg_priv_opts & 0x10) != 0) goto _L768;
            goto _L769;
          }
          iVar9 = r_lld_per_adv_stop(uVar3);
          if (iVar9 == 0) {
            piVar6 = (int *)(*(int *)(_p_llm_env + 8) + iVar4 * 0x44);
            if (((*(ushort *)(*piVar6 + 2) & 3) == 0) && ((char)piVar6[0x10] == '\x02')) {
              r_lld_adv_sync_info_update(iVar4,uVar3,0);
            }
            *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar8 + 0x40) = 0xd;
            if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
               ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
              (*(code *)*_bt_rf_coex_hooks_p)(uVar3,4,0);
            }
          }
          r_sch_plan_rem(*(int *)(_p_llm_env + 8) + iVar8 + 0xc);
          if (iVar9 != 0) goto _L768;
_L777:
          if (*param_1 == 0) {
            return 0;
          }
        }
        else {
          iVar9 = *piVar6;
          if (((*(ushort *)(iVar9 + 2) & 0x33) != 0) || ((char)piVar7[0x10] == '\r')) goto _L769;
          if ((char)piVar7[0x10] == '\n') {
            *(undefined1 *)(piVar7 + 0x10) = 0xb;
          }
          if (((char)piVar6[0x10] == '\x02') && ((char)piVar7[0x10] == '\v')) {
            iVar2 = *piVar7;
            iStack_4c = (uint)*(ushort *)(iVar2 + 4) << 1;
            iStack_50 = (uint)*(ushort *)(iVar2 + 2) << 1;
            uStack_48 = r_llm_per_adv_slot_dur
                                  (*(undefined2 *)((int)piVar7 + 0x2a),*(undefined1 *)(iVar9 + 0x17)
                                  );
            uStack_3e = 0;
            uStack_44 = uStack_48;
            uStack_40 = (ushort)bVar1;
            iVar5 = r_sch_plan_req(&iStack_50);
            if (iVar5 != 0) {
              iVar9 = 0xd;
              goto _L768;
            }
            uStack_5e = *(undefined2 *)(iVar2 + 6);
            local_60 = (undefined2)(uStack_3c >> 1);
            uStack_58 = (undefined2)uStack_38;
            uStack_5c = *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar8 + 0x28);
            uStack_56 = *(undefined1 *)(iVar9 + 0xb);
            uStack_55 = *(undefined1 *)(iVar9 + 0x14);
            uStack_54 = *(undefined1 *)(iVar9 + 0x17);
            iVar9 = r_lld_per_adv_start(uVar3,&local_60);
            if (iVar9 != 0) goto _L768;
            iVar8 = *(int *)(_p_llm_env + 8) + iVar8;
            *(undefined1 *)(iVar8 + 0x40) = 0xc;
            r_lld_adv_sync_info_update(iVar4,uVar3,local_60);
            *(ushort *)(iVar8 + 0x20) = (ushort)bVar1;
            *(undefined4 *)(iVar8 + 0x24) = 0;
            *(undefined4 *)(iVar8 + 0x14) = uStack_38;
            *(undefined1 *)(iVar8 + 0x22) = 0;
            *(uint *)(iVar8 + 0x10) = uStack_3c;
            *(undefined4 *)(iVar8 + 0x18) = uStack_48;
            *(undefined4 *)(iVar8 + 0x1c) = uStack_44;
            r_sch_plan_set(iVar8 + 0xc);
            if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
               ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
              (*(code *)*_bt_rf_coex_hooks_p)(uVar3,4,1);
            }
            goto _L777;
          }
        }
        iVar9 = 0;
      }
      else {
_L769:
        iVar9 = 0xc;
      }
      goto _L768;
    }
  }
  iVar9 = 0x42;
_L768:
  r_llm_cmd_cmp_send(param_2,iVar9);
  return 0;
}

