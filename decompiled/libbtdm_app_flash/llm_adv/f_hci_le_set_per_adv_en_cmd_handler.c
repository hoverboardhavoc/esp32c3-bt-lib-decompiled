/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
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
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
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
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') goto _L809;
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  iVar10 = 0x12;
  if ((1 < *param_1) || (iVar10 = 0x12, 0xef < param_1[1])) goto _L808;
  iVar5 = r_llm_adv_hdl_to_id(0);
  if (iVar5 != 0xff) {
    piVar7 = (int *)(*(int *)(_p_llm_env + 8) + iVar5 * 0x44);
    bVar1 = *(byte *)((int)piVar7 + 0x3d);
    uVar4 = (uint)bVar1;
    if (uVar4 != 0xff) {
      iVar9 = uVar4 * 0x44;
      piVar8 = (int *)(*(int *)(_p_llm_env + 8) + iVar9);
      if ((short)piVar8[0xb] == 0) {
        if (*param_1 == 0) {
          if ((char)piVar8[0x10] == '\v') {
            *(undefined1 *)(piVar8 + 0x10) = 10;
            return 0;
          }
          if ((char)piVar8[0x10] != '\f') {
            iVar10 = 0xfe;
            if ((_sdk_cfg_priv_opts & 0x10) != 0) goto _L808;
            goto _L809;
          }
          iVar10 = r_lld_per_adv_stop(uVar4);
          if (iVar10 == 0) {
            piVar7 = (int *)(*(int *)(_p_llm_env + 8) + iVar5 * 0x44);
            if (((*(ushort *)(*piVar7 + 2) & 3) == 0) && ((char)piVar7[0x10] == '\x02')) {
              r_lld_adv_sync_info_update(iVar5,uVar4,0);
            }
            *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar9 + 0x40) = 0xd;
            if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
               ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
              (*(code *)*_bt_rf_coex_hooks_p)(uVar4,4,0);
            }
          }
          r_sch_plan_rem(*(int *)(_p_llm_env + 8) + iVar9 + 0xc);
          if (iVar10 != 0) goto _L808;
_L835:
          if (*param_1 == 0) {
            return 0;
          }
        }
        else {
          iVar10 = *piVar7;
          uVar2 = *(ushort *)(iVar10 + 2);
          if (((uVar2 & 0x33) != 0) || ((char)piVar8[0x10] == '\r')) goto _L809;
          if ((char)piVar8[0x10] == '\n') {
            *(undefined1 *)(piVar8 + 0x10) = 0xb;
          }
          if ((((uVar2 & 0x13) == 0) && ((char)piVar7[0x10] == '\x02')) &&
             ((char)piVar8[0x10] == '\v')) {
            iVar3 = *piVar8;
            iStack_4c = (uint)*(ushort *)(iVar3 + 4) << 1;
            iStack_50 = (uint)*(ushort *)(iVar3 + 2) << 1;
            uStack_48 = r_llm_per_adv_slot_dur
                                  (*(undefined2 *)((int)piVar8 + 0x2a),
                                   *(undefined1 *)(iVar10 + 0x17));
            uStack_3e = 0;
            uStack_44 = uStack_48;
            uStack_40 = (ushort)bVar1;
            iVar6 = r_sch_plan_req(&iStack_50);
            if (iVar6 != 0) {
              iVar10 = 0xd;
              goto _L808;
            }
            uStack_5e = *(undefined2 *)(iVar3 + 6);
            local_60 = (undefined2)(uStack_3c >> 1);
            uStack_58 = (undefined2)uStack_38;
            uStack_5c = *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar9 + 0x28);
            uStack_56 = *(undefined1 *)(iVar10 + 0xb);
            uStack_55 = *(undefined1 *)(iVar10 + 0x14);
            uStack_54 = *(undefined1 *)(iVar10 + 0x17);
            iVar10 = r_lld_per_adv_start(uVar4,&local_60);
            if (iVar10 != 0) goto _L808;
            iVar9 = *(int *)(_p_llm_env + 8) + iVar9;
            *(undefined1 *)(iVar9 + 0x40) = 0xc;
            r_lld_adv_sync_info_update(iVar5,uVar4,local_60);
            *(ushort *)(iVar9 + 0x20) = (ushort)bVar1;
            *(undefined4 *)(iVar9 + 0x24) = 0;
            *(undefined4 *)(iVar9 + 0x14) = uStack_38;
            *(undefined1 *)(iVar9 + 0x22) = 0;
            *(uint *)(iVar9 + 0x10) = uStack_3c;
            *(undefined4 *)(iVar9 + 0x18) = uStack_48;
            *(undefined4 *)(iVar9 + 0x1c) = uStack_44;
            r_sch_plan_set_hack(iVar9 + 0xc);
            if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
               ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
              (*(code *)*_bt_rf_coex_hooks_p)(uVar4,4,1);
            }
            goto _L835;
          }
        }
        iVar10 = 0;
      }
      else {
_L809:
        iVar10 = 0xc;
      }
      goto _L808;
    }
  }
  iVar10 = 0x42;
_L808:
  r_llm_cmd_cmp_send(param_2,iVar10);
  return 0;
}

