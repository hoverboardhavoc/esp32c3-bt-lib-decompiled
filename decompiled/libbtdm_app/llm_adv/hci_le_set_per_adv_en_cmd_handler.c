/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm_adv.o -> hci_le_set_per_adv_en_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_per_adv_en_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  char cVar2;
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
  
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar6 + 0x18) == '\0') {
    (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,0xc,*(code **)(_r_ip_funcs_p + 0x4b8));
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') goto _L538;
  *(undefined1 *)(_p_llm_env + 0xd7) = 2;
  iVar6 = 0x12;
  if ((1 < *param_1) || (0xef < param_1[1])) goto _L539;
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x544))(0,*(code **)(_r_ip_funcs_p + 0x544));
  if (iVar4 != 0xff) {
    piVar7 = (int *)(*(int *)(_p_llm_env + 8) + iVar4 * 0x44);
    bVar1 = *(byte *)((int)piVar7 + 0x3d);
    uVar9 = (uint)bVar1;
    if (uVar9 != 0xff) {
      iVar10 = uVar9 * 0x44;
      piVar8 = (int *)(*(int *)(_p_llm_env + 8) + iVar10);
      if ((short)piVar8[0xb] == 0) {
        cVar2 = (char)piVar8[0x10];
        if (*param_1 == 0) {
          if (cVar2 == '\v') {
            *(undefined1 *)(piVar8 + 0x10) = 10;
            return 0;
          }
          if (cVar2 != '\f') {
            iVar6 = 0xfe;
            if ((_sdk_cfg_priv_opts & 0x10) != 0) goto _L539;
            goto _L538;
          }
          iVar6 = (**(code **)(_r_ip_funcs_p + 0x30c))(uVar9,*(code **)(_r_ip_funcs_p + 0x30c));
          if (iVar6 == 0) {
            piVar7 = (int *)(*(int *)(_p_llm_env + 8) + iVar4 * 0x44);
            if (((*(ushort *)(*piVar7 + 2) & 3) == 0) && ((char)piVar7[0x10] == '\x02')) {
              (**(code **)(_r_ip_funcs_p + 0x1f0))(iVar4,uVar9,0,*(code **)(_r_ip_funcs_p + 0x1f0));
            }
            *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar10 + 0x40) = 0xd;
            if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
               ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
              (*(code *)*_bt_rf_coex_hooks_p)(uVar9,4,0);
            }
          }
          (**(code **)(_r_ip_funcs_p + 0x6f4))
                    (*(int *)(_p_llm_env + 8) + iVar10 + 0xc,*(code **)(_r_ip_funcs_p + 0x6f4));
          if (iVar6 != 0) goto _L539;
_L565:
          if (*param_1 == 0) {
            return 0;
          }
        }
        else {
          if (cVar2 == '\r') goto _L538;
          iVar6 = *piVar7;
          if (cVar2 == '\n') {
            *(undefined1 *)(piVar8 + 0x10) = 0xb;
          }
          if ((((*(ushort *)(iVar6 + 2) & 0x13) == 0) && ((char)piVar7[0x10] == '\x02')) &&
             ((char)piVar8[0x10] == '\v')) {
            iVar3 = *piVar8;
            iStack_4c = (uint)*(ushort *)(iVar3 + 4) << 1;
            iStack_50 = (uint)*(ushort *)(iVar3 + 2) << 1;
            uStack_48 = (**(code **)(_r_ip_funcs_p + 0x554))
                                  (*(undefined2 *)((int)piVar8 + 0x2a),*(undefined1 *)(iVar6 + 0x17)
                                   ,*(code **)(_r_ip_funcs_p + 0x554));
            uStack_3e = 0;
            uStack_44 = uStack_48;
            uStack_40 = (ushort)bVar1;
            iVar5 = (**(code **)(_r_ip_funcs_p + 0x6f8))
                              (&iStack_50,*(code **)(_r_ip_funcs_p + 0x6f8));
            if (iVar5 != 0) {
              iVar6 = 0xd;
              goto _L539;
            }
            uStack_5e = *(undefined2 *)(iVar3 + 6);
            uStack_60 = (undefined2)(uStack_3c >> 1);
            uStack_58 = (undefined2)uStack_38;
            uStack_5c = *(undefined4 *)(*(int *)(_p_llm_env + 8) + iVar10 + 0x28);
            uStack_56 = *(undefined1 *)(iVar6 + 0xb);
            uStack_55 = *(undefined1 *)(iVar6 + 0x14);
            uStack_54 = *(undefined1 *)(iVar6 + 0x17);
            iVar6 = (**(code **)(_r_ip_funcs_p + 0x308))
                              (uVar9,&uStack_60,*(code **)(_r_ip_funcs_p + 0x308));
            if (iVar6 != 0) goto _L539;
            iVar10 = *(int *)(_p_llm_env + 8) + iVar10;
            *(undefined1 *)(iVar10 + 0x40) = 0xc;
            (**(code **)(_r_ip_funcs_p + 0x1f0))
                      (iVar4,uVar9,uStack_60,*(code **)(_r_ip_funcs_p + 0x1f0));
            *(undefined1 *)(iVar10 + 0x22) = 0;
            *(ushort *)(iVar10 + 0x20) = (ushort)bVar1;
            *(undefined4 *)(iVar10 + 0x14) = uStack_38;
            *(undefined4 *)(iVar10 + 0x24) = 0;
            *(uint *)(iVar10 + 0x10) = uStack_3c;
            *(undefined4 *)(iVar10 + 0x18) = uStack_48;
            *(undefined4 *)(iVar10 + 0x1c) = uStack_44;
            (**(code **)(_r_ip_funcs_p + 0x6fc))(iVar10 + 0xc,*(code **)(_r_ip_funcs_p + 0x6fc));
            if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
               ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
              (*(code *)*_bt_rf_coex_hooks_p)(uVar9,4,1);
            }
            goto _L565;
          }
        }
        iVar6 = 0;
      }
      else {
_L538:
        iVar6 = 0xc;
      }
      goto _L539;
    }
  }
  iVar6 = 0x42;
_L539:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar6,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

