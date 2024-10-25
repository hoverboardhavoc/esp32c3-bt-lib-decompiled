/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> hci.o -> r_hci_send_2_host
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_send_2_host(undefined1 *param_1)

{
  ushort uVar1;
  undefined1 *puVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  ushort uVar7;
  uint uVar8;
  
  puVar2 = param_1 + -0xc;
  iVar4 = r_hci_evt_mask_check(puVar2);
  if (iVar4 != 0) goto _L46;
  if (hci_ext_host != '\0') {
    r_hci_tl_send(puVar2);
    return;
  }
  uVar6 = 0;
  switch(*(short *)(param_1 + -8) + -0x1101) {
  case 0:
  case 1:
    uVar7 = 8;
    if (*(short *)(param_1 + -4) == 0) goto _L22;
    iVar4 = r_hci_look_for_cmd_desc();
    if (iVar4 == 0) goto _L29;
    uVar8 = (int)(uint)*(byte *)(iVar4 + 2) >> 4;
    goto _L42;
  case 2:
    iVar4 = r_hci_look_for_evt_desc(param_1[-4]);
    break;
  case 3:
    iVar4 = r_hci_look_for_le_evt_desc(*param_1);
    break;
  default:
    goto _L29;
  case 5:
    goto _L17;
  }
  if (iVar4 == 0) {
_L29:
    uVar3 = 4;
_L16:
    uVar6 = 0x3ff;
    uVar5 = *(undefined2 *)(param_1 + -8);
  }
  else {
    uVar8 = (uint)*(byte *)(iVar4 + 1);
_L42:
    uVar8 = uVar8 & 3;
    if (uVar8 == 1) {
      uVar7 = *(ushort *)(param_1 + -6);
      iVar4 = r_sdk_config_get_opts();
      uVar5 = *(undefined2 *)(param_1 + -6);
      if (uVar7 < *(byte *)(iVar4 + 0xd)) {
        uVar8 = (**(code **)(_r_hli_funcs_p + 0x14))(uVar5,*(code **)(_r_hli_funcs_p + 0x14));
        uVar7 = 9;
        if (uVar8 != 0xff) {
          uVar7 = (ushort)((uVar8 & 0xff) << 8) | 9;
        }
_L22:
        *(ushort *)(param_1 + -6) = uVar7;
        r_ke_msg_send(param_1);
        return;
      }
      uVar6 = 0x3e6;
    }
    else {
      if (uVar8 == 0) {
        uVar7 = 8;
        goto _L22;
      }
      uVar3 = 3;
      uVar6 = 3;
      if (uVar8 != 2) goto _L16;
_L17:
      uVar1 = *(ushort *)(param_1 + -6);
      iVar4 = r_sdk_config_get_opts(uVar6);
      uVar7 = 5;
      if (uVar1 < *(byte *)(iVar4 + 0xd)) goto _L22;
      uVar6 = 0x3f7;
      uVar5 = *(undefined2 *)(param_1 + -6);
    }
    uVar3 = *(undefined2 *)(param_1 + -8);
  }
  r_assert_param(uVar3,uVar5,"hci.c",uVar6);
  r_assert_param(*(undefined2 *)(param_1 + -8),*(undefined2 *)(param_1 + -4),"hci.c",0x432);
_L46:
  r_ke_msg_free(puVar2);
  return;
}

