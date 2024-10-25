/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_ecc_multiplication_event_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ecc_multiplication_event_handler(void)

{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined2 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 auStack_68 [2];
  undefined2 local_66 [17];
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined1 auStack_3c [2];
  undefined2 auStack_3a [17];
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  r_ke_event_clear(1);
  iVar3 = r_co_list_pop_front(&ecc_env);
  if (iVar3 == 0) {
    r_assert_err("ecc_p256.c",0x857);
  }
  else if (*(int *)(iVar3 + 4) == 0) {
    if (*(short *)(iVar3 + 0x13e) != 0xff) {
      puVar4 = (undefined1 *)r_ke_msg_alloc(*(undefined2 *)(iVar3 + 0x13c),0xff,0x40);
      memset(auStack_68,0,0x22);
      uStack_44 = 0;
      uStack_40 = 0;
      memset(auStack_3c,0,0x22);
      uStack_18 = 0;
      uStack_14 = 0;
      r_GF_Point_Jacobian_To_Affine256(iVar3 + 8,auStack_68,auStack_3c);
      if (*(int *)(iVar3 + 0x148) != 0) {
        r_ke_free();
      }
      r_ke_free(iVar3);
      puVar5 = local_66;
      puVar6 = puVar4 + 0x1e;
      do {
        uVar2 = *puVar5;
        puVar5 = puVar5 + 1;
        *puVar6 = (char)uVar2;
        puVar6[1] = (char)((ushort)uVar2 >> 8);
        bVar1 = puVar4 != puVar6;
        puVar6 = puVar6 + -2;
      } while (bVar1);
      puVar8 = auStack_68;
      puVar6 = puVar4 + 0x3e;
      do {
        uVar2 = *(undefined2 *)(puVar8 + 0x2e);
        puVar7 = puVar6 + -2;
        puVar8 = puVar8 + 2;
        puVar6[1] = (char)((ushort)uVar2 >> 8);
        *puVar6 = (char)uVar2;
        puVar6 = puVar7;
      } while (puVar4 + 0x1e != puVar7);
      r_ke_msg_send(puVar4);
    }
  }
  else {
    r_ecc_point_multiplication_win_256();
    r_co_list_push_back(&ecc_env,iVar3);
  }
  if (_ecc_env != 0) {
    r_ke_event_set(1);
  }
  return;
}

